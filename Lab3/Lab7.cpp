#include <iostream>
#include "Culture.h"
using namespace std;

void menu() {
    cout << "\nМЕНЮ\n";
    cout << "1. Вивести всі культури\n";
    cout << "2. Порівняти дві культури (==)\n";
    cout << "3. Скласти дві культури (+)\n";
    cout << "4. Довжина назви [ ]\n";
    cout << "5. Ініціалізувати культуру ( )\n";
    cout << "6. Введення нової культури (>>)\n";
    cout << "0. Вийти\n";
}

int main() {
	setlocale(LC_ALL, "ukr");
    system("chcp 65001");
    Culture c1("Соя", 'Б', 13000, 45);
    Culture c2("Чумиза", 'З', 8000, 17);
    Culture c3("Рис", 'З', 25650, 24);
    Culture temp;

    int choice;
    do {
        menu();
        cout << "\nВаш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n--- Культури ---\n";
            cout << c1 << "\n" << c2 << "\n" << c3 << "\n";
            break;

        case 2:
            cout << "Соя == Чумиза? " << (c1 == c2 ? "Так" : "Ні") << "\n";
            break;

        case 3:
            temp = c1 + c2;
            cout << "Сума площі та врожайності:\n" << temp << "\n";
            break;

        case 4:
            cout << "Довжина назви \"Рис\": " << c3[0] << "\n";
            break;

        case 5:
            temp("Гречка", 'Б', 10000, 30);
            cout << "Ініціалізовано:\n" << temp << "\n";
            break;

        case 6:
            cin >> temp;
            cout << "Ви ввели:\n" << temp << "\n";
            break;

        case 0:
            cout << "Вихід...\n";
            break;

        default:
            cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}
