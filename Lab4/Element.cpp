#include "Element.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Element::Element() : atomicNumber(0), massNumber(0), halfLife(0) {
    memset(name, 0, sizeof(name));
}

void Element::input() {
    cout << "Атомний номер: ";
    cin >> atomicNumber;

    string temp;
    cout << "Назва (до 29 символів): ";
    cin >> temp;
    strncpy_s(name, temp.c_str(), sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';

    cout << "Масове число: ";
    cin >> massNumber;

    cout << "Період напіврозпаду (роки): ";
    cin >> halfLife;
}

void Element::display() const {
    cout << "Атомний номер: " << atomicNumber
        << ", Назва: " << name
        << ", Масове число: " << massNumber
        << ", Період напіврозпаду (роки): " << halfLife << "\n";
}

void Element::writeToFile(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(this), sizeof(Element));
}

void Element::readFromFile(ifstream& in) {
    in.read(reinterpret_cast<char*>(this), sizeof(Element));
}

streamsize Element::recordSize() {
    return sizeof(Element);
}
