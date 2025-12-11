#pragma once
#include <string>

#define PRINT_TYPE 2
#define DEBUG

struct Culture {
    std::wstring name;
    wchar_t type;
    int area;
    int vro;
};

void fillCultures(Culture* arr, int size);
void sortCultures(Culture* arr, int size);
void printCultures(const Culture* arr, int size);
