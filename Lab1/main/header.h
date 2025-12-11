#pragma once
#include <string>

#define PRINT_TYPE 2 // 1 - user input, 2 - predefined data

struct Element {
    int atomicNumber;
    std::wstring name;
    int massNumber;
    int halfLife;
};

void fillElements(Element* arr, int size);
void sortElements(Element* arr, int size);
void printElements(const Element* arr, int size);