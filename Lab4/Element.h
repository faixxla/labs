#pragma once
#include <fstream>
using namespace std;

class Element {
private:
    int atomicNumber;
    char name[30];
    int massNumber;
    double halfLife;

public:
    Element();
    void input();
    void display() const;

    void writeToFile(ofstream& out) const;
    void readFromFile(ifstream& in);

    static streamsize recordSize();
};
