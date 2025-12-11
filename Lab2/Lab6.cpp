#include "Header.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void printHeader() {
    cout << "Назва\tТип\tПлоща (га)\tВрожайність (ц/га)" << endl;
    cout << "-------------------------------------------" << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Crop crops1[1] = { Crop() };
    Crop crops2[1];
    Crop crops3[1];

    string name;
    char type;
    double area, vro;

    crops1[0].setName("Назва");
    crops1[0].setType('Т');
    crops1[0].setArea(0);
    crops1[0].setVro(0);

    crops2[0] = Crop(crops1[0]);
    crops3[0] = Crop(crops1[0]);

    int choice;
    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Показати всі культури\n";
        cout << "2. Змінити параметри\n";
        cout << "3. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nПервинна таблиця:\n";
            printHeader();
            crops1[0].show();
            crops2[0].show();
            crops3[0].show();
            break;

        case 2:
            int idx;
            cout << "Виберіть масив (1, 2, 3): ";
            cin >> idx;
            if (idx < 1 || idx > 3) break;

            cout << "Нові значення (назва, тип, площа, врожайність): ";
            cin >> name >> type >> area >> vro;

            if (idx == 1) {
                crops1[0].setName(name);
                crops1[0].setType(type);
                crops1[0].setArea(area);
                crops1[0].setVro(vro);
            }
            else if (idx == 2) {
                crops2[0].setName(name);
                crops2[0].setType(type);
                crops2[0].setArea(area);
                crops2[0].setVro(vro);
            }
            else {
                crops3[0].setName(name);
                crops3[0].setType(type);
                crops3[0].setArea(area);
                crops3[0].setVro(vro);
            }
            break;

        case 3:
            cout << "Завершення програми.\n";
            break;

        default:
            cout << "Невірний вибір.\n";
        }

    } while (choice != 3);

    return 0;
}

