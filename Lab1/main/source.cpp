#include "header.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void fillCultures(Culture* arr, int size) {
#ifdef DEBUG
    cout << "[DEBUG] Start fillCultures() - " << __DATE__ << " " << __TIME__ << endl;
#endif

#if PRINT_TYPE == 1
    for (int i = 0; i < size; ++i) {
        wcout << L"Введіть найменування культури: ";
        wcin >> arr[i].name;
        wcout << L"Введіть тип (Б/З): ";
        wcin >> arr[i].type;
        wcout << L"Введіть посівну площу (га): ";
        wcin >> arr[i].area;
        wcout << L"Введіть врожайність (ц/га): ";
        wcin >> arr[i].vro;
    }
#elif PRINT_TYPE == 2
    const wstring names[] = { L"Соя", L"Чумиза", L"Рис" };
    const wchar_t types[] = { L'Б', L'З' };
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i].name = names[i];
        arr[i].type = types[rand() % 2];
        arr[i].area = rand() % 30000 + 1000;
        arr[i].vro = rand() % 50 + 10;
    }
#else
#error Invalid PRINT_TYPE
#endif

#ifdef DEBUG
    cout << "[DEBUG] End fillCultures() - File: " << __FILE__ << " Function: " << __func__ << endl;
#endif
}

void sortCultures(Culture* arr, int size) {
#ifdef DEBUG
    cout << "[DEBUG] Start sortCultures() - " << __DATE__ << " " << __TIME__ << endl;
#endif

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].name > arr[j + 1].name) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

#ifdef DEBUG
    cout << "[DEBUG] End sortCultures() - File: " << __FILE__ << " Function: " << __func__ << endl;
#endif
}

void printCultures(const Culture* arr, int size) {
#ifdef DEBUG
    cout << "[DEBUG] Start printCultures() - " << __DATE__ << " " << __TIME__ << endl;
#endif

    wcout << setw(20) << L"Найменування"
        << setw(10) << L"Тип"
        << setw(20) << L"Площа (га)"
        << setw(20) << L"Врожайність (ц/га)" << endl;

    for (int i = 0; i < size; ++i) {
        wcout << setw(20) << arr[i].name
            << setw(10) << arr[i].type
            << setw(20) << arr[i].area
            << setw(20) << arr[i].vro << endl;
    }

#ifdef DEBUG
    cout << "[DEBUG] End printCultures() - File: " << __FILE__ << " Function: " << __func__ << endl;
#endif
}
