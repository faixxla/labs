#include <iostream>
#include <stdexcept>
#include "Tasks.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001");
    try {
        cout << "=== Завдання 5.1: NumericBox ===\n";
        NumericBox<int>    a;// за замовчуванням
        NumericBox<int>    b(10);// з параметром
        NumericBox<double> c(2.5);

        cout << "a = "; a.print(); 
        cout << "\n";
        cout << "b = " << b << "\n";
        cout << "c = " << c << "\n";

        a = b;
        cout << "Після a = b: a = " << a << "\n";

        b = NumericBox<double>(7.9);
        cout << "Після b = NumericBox<double>(7.9): b = " << b << "\n";

        auto d = b + c;
        cout << "d = b + c = " << d << "\n";

        cout << "\n=== Завдання 5.2.1: Vector (скалярний добуток) ===\n";
        VectorTask::runFromFile("./data/vectors.txt");

        cout << "\n=== Завдання 5.2.2: List (видалення першого і останнього) ===\n";
        ListTask::runFromFile("./data/list_input.txt");

        cout << "\n=== Завдання 5.2.3: Map (студенти, які не склали) ===\n";
        MapTask::runFromFile("./data/students.txt");

        cout << "\nУсе виконано успішно.\n";
    }
    catch (const exception& ex) {
        cerr << "\n[main] Фатальна помилка: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
