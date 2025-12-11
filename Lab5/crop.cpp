#include "Crop.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
Crop::Crop() : type(' '), area(0), vro(0) {
    memset(name, 0, sizeof(name));
}

void Crop::input() {
    string temp;
    cout << "Назва (до 29 символів): ";
    cin >> temp;
    strncpy_s(name, temp.c_str(), sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';

    cout << "Тип (Б/З): ";
    cin >> type;
    cout << "Площа (га): ";
    cin >> area;
    cout << "Врожайність (ц/га): ";
    cin >> vro;
}

void Crop::display() const {
    cout << "Назва: " << name
        << ", Тип: " << type
        << ", Площа: " << area
        << ", Врожайність: " << vro << "\n";
}

void Crop::writeToFile(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(this), sizeof(Crop));
}

void Crop::readFromFile(ifstream& in) {
    in.read(reinterpret_cast<char*>(this), sizeof(Crop));
}
std::streamsize Crop::recordSize() {
    return sizeof(Crop);
}
