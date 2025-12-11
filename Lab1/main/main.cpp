#include <iostream>
#include <locale>
#include "header.h"

using namespace std;

int main() {
    locale::global(locale("uk_UA.UTF-8"));
    system("chcp 65001");

    const int SIZE = 3;
    Element arr[SIZE];
    int choice;

    do {
        wcout << L"\nМЕНЮ:\n";
        wcout << L"1. Заповнити структуру\n";
        wcout << L"2. Відсортувати структуру за назвою\n";
        wcout << L"3. Надрукувати структуру\n";
        wcout << L"4. Вихід\n";
        wcout << L"Ваш вибір: ";
        wcin >> choice;

        switch (choice) {
        case 1:
            fillElements(arr, SIZE);
            break;
        case 2:
            sortElements(arr, SIZE);
            break;
        case 3:
            printElements(arr, SIZE);
            break;
        case 4:
            wcout << L"Завершення програми...\n";
            break;
        default:
            wcout << L"Неправильний вибір! Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}