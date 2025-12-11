#pragma once
#include <iostream>
using namespace std;

class Culture {
private:
    char* name;
    char type;
    double area;
    double yield;

public:
    Culture();
    Culture(const char* n, char t, double a, double y);
    Culture(const Culture& other);
    ~Culture();

    Culture& operator=(const Culture& other);
    Culture operator+(const Culture& other) const;
    bool operator==(const Culture& other) const;

    int operator[](int);
    void operator()(const char* n, char t, double a, double y);


    friend istream& operator>>(istream& in, Culture& c);
    friend ostream& operator<<(ostream& out, const Culture& c);
};
