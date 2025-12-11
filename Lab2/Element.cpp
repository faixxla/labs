#include "Element.h"
#include <iomanip>

Element::Element() : atomicNumber(0), name("Unknown"), massNumber(0), halfLife(0.0) {}

Element::Element(int num, std::string n, int mass, double life)
    : atomicNumber(num), name(n), massNumber(mass), halfLife(life) {
}

// --- Функції-члени ---

// Привласнення
Element& Element::operator=(const Element& other) {
    if (this == &other) return *this; // Захист від самопривласнення
    atomicNumber = other.atomicNumber;
    name = other.name;
    massNumber = other.massNumber;
    halfLife = other.halfLife;
    return *this;
}

// Складання (Element + Element)
// Логіка: створюємо гіпотетичний елемент із сумою мас та номерів
Element Element::operator+(const Element& other) {
    Element temp;
    temp.atomicNumber = this->atomicNumber + other.atomicNumber;
    temp.massNumber = this->massNumber + other.massNumber;
    temp.halfLife = (this->halfLife + other.halfLife) / 2; // Середнє значення
    temp.name = this->name + "-" + other.name; // Зчеплення назв
    return temp;
}

// Порівняння (Element == Element)
bool Element::operator==(const Element& other) {
    return (atomicNumber == other.atomicNumber &&
        massNumber == other.massNumber &&
        name == other.name);
}

// Перевантаження [], повертає довжину назви
int Element::operator[](int index) {
    return name.length();
}

// Перевантаження () - ініціалізація
void Element::operator()(int num, std::string n, int mass, double life) {
    atomicNumber = num;
    name = n;
    massNumber = mass;
    halfLife = life;
}

// --- Дружні функції ---

// Складання (Element + int)
Element operator+(const Element& e, int value) {
    Element temp = e;
    temp.massNumber += value; // Збільшуємо масу на число
    return temp;
}

// Порівняння (Element == int)
bool operator==(const Element& e, int atomicNum) {
    return e.atomicNumber == atomicNum;
}

// Потокове виведення <<
std::ostream& operator<<(std::ostream& os, const Element& e) {
    os << "| " << std::setw(5) << e.atomicNumber
        << " | " << std::setw(15) << e.name
        << " | " << std::setw(6) << e.massNumber
        << " | " << std::setw(10) << e.halfLife << " |";
    return os;
}

// Потокове введення >>
std::istream& operator>>(std::istream& is, Element& e) {
    std::cout << "  > Atomic Num: "; is >> e.atomicNumber;
    std::cout << "  > Name: "; is >> e.name;
    std::cout << "  > Mass Num: "; is >> e.massNumber;
    std::cout << "  > Half-life: "; is >> e.halfLife;
    return is;
}