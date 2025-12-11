#ifndef CROP_H
#define CROP_H
#include <string>

class Crop {
private:
    std::string name;
    char type;
    double area;
    double vro;

public:
    Crop();
    Crop(std::string name, char type, double area, double vro);
    Crop(const Crop& other);

    std::string getName() const;
    char getType() const;
    double getArea() const;
    double getVro() const;

    void setName(std::string name);
    void setType(char type);
    void setArea(double area);
    void setVro(double vro);

    void show() const;
};

#endif
#pragma once
