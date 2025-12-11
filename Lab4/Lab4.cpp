#include "Element.h"
#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

const int MAX = 100;
const char* FILENAME = "elements.bin";

void saveAllToFile(Element arr[], int count) {
    ofstream out(FILENAME, ios::binary | ios::trunc);
    for (int i = 0; i < count; ++i) {
        arr[i].writeToFile(out);
    }
    out.close();
    cout << "Усі об'єкти збережено у файл.\n";
}

int loadAllFromFile(Element arr[]) {
    ifstream in(FILENAME, ios::binary);
    if (!in) {
        cout << "Файл не знайдено.\n";
        return 0;
    }

    int count = 0;
    while (in.read(reinterpret_cast<char*>(&arr[count]), Element::recordSize()) && count < MAX) {
        ++count;
    }
    in.close();
    cout << "Зчитано " << count << " об'єктів з файлу.\n";
    return count;
}

void saveOneToFile(Element& elem, int index) {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Файл не знайдено.\n";
        return;
    }

    file.seekp(index * Element::recordSize(), ios::beg);
    file.write(reinterpret_cast<const char*>(&elem), Element::recordSize());
    file.close();
    cout << "Об'єкт записано на позицію " << index << ".\n";
}
void readOneFromFile(int index) {
    ifstream file(FILENAME, ios::binary);
    if (!file) {
        cout << "Файл не знайдено.\n";
        return;
    }

    file.seekg(0, ios::end);
    streamsize size = file.tellg();
    int total = size / Element::recordSize();

    if (index < 0 || index >= total) {
        cout << "Невірний індекс. У файлі лише " << total << " записів.\n";
        file.close();
        return;
    }

    file.seekg(index * Element::recordSize(), ios::beg);
    Element e;
    e.readFromFile(file);
    e.display();
    file.close();
}

void printMenu() {
    cout << "\n=== Меню ===\n"
        << "1. Додати елемент\n"
        << "2. Зберегти 1 об'єкт у файл\n"
        << "3. Зчитати 1 об'єкт з файлу\n"
        << "4. Зберегти всі об'єкти у файл\n"
        << "5. Зчитати всі об'єкти з файлу\n"
        << "6. Показати всі об'єкти\n"
        << "0. Вихід\n";
}

int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001");

    Element elems[MAX];
    int count = 0;
    int choice;

    do {
        printMenu();
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count < MAX) {
                elems[count].input();
                count++;
            }
            else {
                cout << "Досягнуто максимум записів.\n";
            }
            break;

        case 2: {
            int idx;
            cout << "Введіть індекс (0.." << count - 1 << "): ";
            cin >> idx;
            if (idx >= 0 && idx < count) {
                saveOneToFile(elems[idx], idx);
            }
            else {
                cout << "Невірний індекс.\n";
            }
            break;
        }

        case 3: {
            int idx;
            cout << "Введіть індекс для зчитування: ";
            cin >> idx;
            readOneFromFile(idx);
            break;
        }

        case 4:
            saveAllToFile(elems, count);
            break;

        case 5:
            count = loadAllFromFile(elems);
            break;

        case 6:
            for (int i = 0; i < count; ++i) {
                cout << "[" << i << "] ";
                elems[i].display();
            }
            break;

        case 0:
            cout << "Вихід з програми.\n";
            break;

        default:
            cout << "Невідома команда!\n";
        }
    } while (choice != 0);

    return 0;
}
