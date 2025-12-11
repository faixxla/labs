#pragma once
#include <fstream>
using namespace std;
class Crop {
private:
    char name[30];
    char type;
    double area;
    double vro;

public:
    Crop();
    void input();
    void display() const;

    void writeToFile(ofstream& out) const;
    void readFromFile(ifstream& in);

    static streamsize recordSize();
};
