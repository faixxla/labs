#include "Header.h"
#include <iostream>
using namespace std;

Crop::Crop() : name(""), type(' '), area(0), vro(0) {}

Crop::Crop(string name, char type, double area, double vro)
    : name(name), type(type), area(area), vro(vro) {
}

Crop::Crop(const Crop& other)
    : name(other.name), type(other.type), area(other.area), vro(other.vro) {
}

string Crop::getName() const { return name; }
char Crop::getType() const { return type; }
double Crop::getArea() const { return area; }
double Crop::getVro() const { return vro; }

void Crop::setName(string name) { this->name = name; }
void Crop::setType(char type) { this->type = type; }
void Crop::setArea(double area) { this->area = area; }
void Crop::setVro(double vro) { this->vro = vro; }

void Crop::show() const {
    cout << name << "\t" << type << "\t" << area << "\t\t" << vro << endl;
}
