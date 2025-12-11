#pragma once
#include <iostream>
#include <string>

class Element {
private:
    int atomicNumber;
    std::string name;
    int massNumber;
    double halfLife;

public:
    Element();
    Element(int num, std::string n, int mass, double life);

    Element& operator=(const Element& other);
    Element operator+(const Element& other);
    bool operator==(const Element& other);
    int operator[](int index);
    void operator()(int num, std::string n, int mass, double life);

    friend Element operator+(const Element& e, int value);
    friend bool operator==(const Element& e, int atomicNum);
    friend std::ostream& operator<<(std::ostream& os, const Element& e);
    friend std::istream& operator>>(std::istream& is, Element& e);
};