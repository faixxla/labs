#define _CRT_SECURE_NO_WARNINGS
#include "Culture.h"
#include <cstring>

Culture::Culture() {
    name = new char[1];
    name[0] = '\0';
    type = ' ';
    area = 0;
    yield = 0;
}

Culture::Culture(const char* n, char t, double a, double y) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    type = t;
    area = a;
    yield = y;
}

Culture::Culture(const Culture& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    type = other.type;
    area = other.area;
    yield = other.yield;
}

Culture::~Culture() {
    delete[] name;
}

Culture& Culture::operator=(const Culture& other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        type = other.type;
        area = other.area;
        yield = other.yield;
    }
    return *this;
}

Culture Culture::operator+(const Culture& other) const {
    Culture result(*this);
    result.area += other.area;
    result.yield += other.yield;
    return result;
}

bool Culture::operator==(const Culture& other) const {
    if (strcmp(this->name, other.name) == 0 && this->type == other.type)
        return true;
    else
        return false;
}

int Culture::operator[](int) {
    return strlen(name);
}

void Culture::operator()(const char* n, char t, double a, double y) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    type = t;
    area = a;
    yield = y;
}
istream& operator>>(istream& in, Culture& c) {
    char buffer[100];
    cout << "Введіть найменування: ";
    in >> ws;
    in.getline(buffer, 100);

    delete[] c.name;
    c.name = new char[strlen(buffer) + 1];
    strcpy(c.name, buffer);

    cout << "Введіть тип (одна літера): ";
    in >> ws;
    in.get(c.type);


    cout << "Введіть посівну площу (га): ";
    in >> c.area;

    cout << "Введіть врожайність (ц/га): ";
    in >> c.yield;

    return in;
}


ostream& operator<<(ostream& out, const Culture& c) {
    out << "Найменування: " << c.name << "\n";
    out << "Тип: " << c.type << "\n";
    out << "Посівна площа: " << c.area << " га\n";
    out << "Врожайність: " << c.yield << " ц/га\n";
    return out;
}
