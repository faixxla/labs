#include "header.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void fillElements(Element* arr, int size) {

#if PRINT_TYPE == 1
    for (int i = 0; i < size; ++i) {
        wcout << L"Введіть атомний номер: ";
        wcin >> arr[i].atomicNumber;
        wcout << L"Введіть назву елемента: ";
        wcin >> arr[i].name;
        wcout << L"Введіть масове число: ";
        wcin >> arr[i].massNumber;
        wcout << L"Введіть період напіврозпаду (років): ";
        wcin >> arr[i].halfLife;
    }
#elif PRINT_TYPE == 2
    const int atomicNumbers[] = { 93, 97, 98 };
    const wstring names[] = { L"Нептуній", L"Берклій", L"Каліфорній" };
    const int massNumbers[] = { 237, 247, 251 };
    const int halfLives[] = { 220000, 700, 660 };

    for (int i = 0; i < size; ++i) {
        if (i < 3) {
            arr[i].atomicNumber = atomicNumbers[i];
            arr[i].name = names[i];
            arr[i].massNumber = massNumbers[i];
            arr[i].halfLife = halfLives[i];
        }
        else {
            arr[i].atomicNumber = 0;
            arr[i].name = L"Пусто";
            arr[i].massNumber = 0;
            arr[i].halfLife = 0;
        }
    }
#else
#error Invalid PRINT_TYPE
#endif
}

void sortElements(Element* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].name > arr[j + 1].name) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printElements(const Element* arr, int size) {


    wcout << L"-------------------------------------------------------------------------------" << endl;
    wcout << setw(10) << L"Атом. №"
        << setw(15) << L"Назва"
        << setw(15) << L"Масове число"
        << setw(25) << L"Період напіврозпаду" << endl;
    wcout << L"-------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        wcout << setw(10) << arr[i].atomicNumber
            << setw(15) << arr[i].name
            << setw(15) << arr[i].massNumber
            << setw(25) << arr[i].halfLife << endl;
    }
}