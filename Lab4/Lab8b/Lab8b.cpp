#include <iostream>
#include <string>
using namespace std;

class BOOK {
protected:
    string title;
    string author;
    int pages;

public:
    BOOK(string t, string a, int p)
        : title(t), author(a), pages(p) {
    }

    virtual void print() const {
        cout << "Назва: " << title << ", Автор: " << author << ", Сторінок: " << pages << endl;
    }

    string getTitle() const {
        return title;
    }
};

class LIBRARY : public BOOK {
private:
    bool isAvailable;
    int inStock;
    int totalCopies;

public:
    LIBRARY(string t, string a, int p, bool avail, int stock, int total)
        : BOOK(t, a, p), isAvailable(avail), inStock(stock), totalCopies(total) {
    }

    void print() const override {
        BOOK::print();
        cout << "Наявність: " << (isAvailable ? "Так" : "Ні")
            << ", В наявності: " << inStock
            << ", Зареєстровано: " << totalCopies << endl;
    }

    bool hasTitle(const string& t) const {
        return title == t;
    }

    bool isInLibrary() const {
        return isAvailable && inStock > 0;
    }

    void takeBook() {
        if (inStock > 0) {
            inStock--;
            if (inStock == 0)
                isAvailable = false;
            cout << "Книгу '" << title << "' взяли почитати." << endl;
        }
        else {
            cout << "Немає екземплярів книги '" << title << "' у бібліотеці!" << endl;
        }
    }

    void returnBook(bool registered) {
        if (!registered) {
            cout << "Цей екземпляр не зареєстрований у цій бібліотеці!" << endl;
            return;
        }
        if (inStock < totalCopies) {
            inStock++;
            isAvailable = true;
            cout << "Книгу '" << title << "' повернули в бібліотеку." << endl;
        }
        else {
            cout << "Усі екземпляри вже в бібліотеці. Неможливо повернути!" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001");

    LIBRARY books[3] = {
        LIBRARY("Book", "Р. Кван", 500, true, 2, 2),
        LIBRARY("Граф Монте-Крісто", "О. Дюма", 1000, true, 1, 2),
        LIBRARY("1984", "Дж. Орвелл", 300, false, 0, 1)
    };

    int choice;
    do {
        cout << "\n=== МЕНЮ БІБЛІОТЕКИ ===\n";
        cout << "1. Показати всі книги\n";
        cout << "2. Пошук книги за назвою\n";
        cout << "3. Взяти книгу\n";
        cout << "4. Повернути книгу\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore(); // для очищення буфера

        if (choice == 1) {
            cout << "\n--- Перелік книг ---\n";
            for (const auto& b : books) {
                b.print();
                cout << "---------------------\n";
            }
        }
        else if (choice == 2) {
            string title;
            cout << "Введіть назву книги: ";
            getline(cin, title);
            bool found = false;
            for (const auto& b : books) {
                if (b.hasTitle(title)) {
                    b.print();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Книгу '" << title << "' не знайдено.\n";
            }
        }
        else if (choice == 3) {
            string title;
            cout << "Введіть назву книги для взяття: ";
            getline(cin, title);
            bool found = false;
            for (auto& b : books) {
                if (b.hasTitle(title)) {
                    b.takeBook();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Книгу не знайдено.\n";
            }
        }
        else if (choice == 4) {
            string title;
            char reg;
            cout << "Введіть назву книги для повернення: ";
            getline(cin, title);
            cout << "Цей екземпляр зареєстрований у бібліотеці? (y/n): ";
            cin >> reg;
            cin.ignore(); // очищення буфера
            bool isRegistered = (reg == 'y' || reg == 'Y');

            bool found = false;
            for (auto& b : books) {
                if (b.hasTitle(title)) {
                    b.returnBook(isRegistered);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Книгу не знайдено.\n";
            }
        }
        else if (choice != 0) {
            cout << "Невідома опція. Спробуйте ще раз.\n";
        }

    } while (choice != 0);

    cout << "Програму завершено.\n";
    return 0;
}
