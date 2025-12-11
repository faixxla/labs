#include "Number.h"
#include "STLTasks.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>

int main() {
    try {
        std::cout << "=== Завдання 5.1: Шаблонний клас ===" << std::endl;

        Number<int> n1(5), n2(10);
        n1.print(); 
        n2.print(); 

        n1 = n2;
        n1.print();

        int sumInt = n1 + n2;
        std::cout << "Сума цілих: " << sumInt << std::endl;

        Number<double> d1(3.5), d2(2.5);
        d1.print(); 
        d2.print();

        d1 = d2;
        d1.print();

        double sumDouble = d1 + d2;
        std::cout << "Сума дійсних: " << sumDouble << std::endl;

        auto sumMixed = n1 + d1;
        std::cout << "Сума змішаних типів: " << sumMixed << std::endl;

        std::cout << "\n=== Завдання 5.2: STL Контейнери ===" << std::endl;
        std::vector<int> vec = { 1, 2, 2, 3, 4, 4, 5 };
        removeDuplicates(vec);
        std::cout << "Унікальні значення вектора: ";
        for (int v : vec) std::cout << v << " ";
        std::cout << std::endl;

        std::list<int> lst = { 1, 2, 3, 4, 5 };
        std::cout << "Перевірка списку: ";
        if (isSorted(lst)) std::cout << "Список впорядкований." << std::endl;
        else std::cout << "Список не впорядкований." << std::endl;

        lst.push_back(0);
        std::cout << "Перевірка списку після додавання 0: ";
        if (isSorted(lst)) std::cout << "Список впорядкований." << std::endl;
        else std::cout << "Список не впорядкований." << std::endl;

        std::map<std::string, int> students = { {"Alice", 90}, {"Bob", 85} };
        addOrUpdateStudent(students, "Charlie", 95);
        addOrUpdateStudent(students, "Alice", 92);

        std::cout << "Список студентів та оцінки:" << std::endl;
        for (const auto& student : students) {
            std::cout << student.first << ": " << student.second << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
