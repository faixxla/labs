#include <iostream>
#include <string>

using namespace std;

class SOBAKA {
protected:
    double vaga;
    int vik;

public:
    SOBAKA(double v = 5.0, int a = 2) : vaga(v), vik(a) {}

    virtual void druk() {
        cout << "Вага: " << vaga << " кг, Вік: " << vik << " років" << endl;
    }

    void golos() {
        if (vaga >= 10)
            cout << "ГАВ" << endl;
        else
            cout << "гав" << endl;
    }

    void setVaga(double v) { vaga = v; }
    void setVik(int v) { vik = v; }
};

class SPANIEL : public SOBAKA {
private:
    string kolir;

public:
    SPANIEL(double v = 6.0, int a = 3, const string& k = "коричневий")
        : SOBAKA(v, a), kolir(k) {
    }

    void druk() override {
        cout << "--- SPANIEL ---" << endl;
        SOBAKA::druk();
        cout << "Колір: " << kolir << endl;
    }

    void setKolir(const string& k) { kolir = k; }
};

class DOG : public SOBAKA {
private:
    double zrist;

public:
    DOG(double v = 12.0, int a = 4, double z = 45.0)
        : SOBAKA(v, a), zrist(z) {
    }

    void druk() override {
        cout << "--- DOG ---" << endl;
        SOBAKA::druk();
        cout << "Зріст: " << zrist << " см" << endl;
    }

    void setZrist(double z) { zrist = z; }
};


int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001");
    SPANIEL mySpaniel;
    DOG myDog;
    int choice;

    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Змінити вагу SPANIEL\n";
        cout << "2. Змінити вік SPANIEL\n";
        cout << "3. Змінити колір SPANIEL\n";
        cout << "4. Змінити вагу DOG\n";
        cout << "5. Змінити вік DOG\n";
        cout << "6. Змінити зріст DOG\n";
        cout << "7. Вивести SPANIEL\n";
        cout << "8. Вивести DOG\n";
        cout << "9. Голос SPANIEL\n";
        cout << "10. Голос DOG\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double v;
            cout << "Нова вага для SPANIEL: ";
            cin >> v;
            mySpaniel.setVaga(v);
            break;
        }
        case 2: {
            int v;
            cout << "Новий вік для SPANIEL: ";
            cin >> v;
            mySpaniel.setVik(v);
            break;
        }
        case 3: {
            string k;
            cout << "Новий колір: ";
            cin.ignore();
            getline(cin, k);
            mySpaniel.setKolir(k);
            break;
        }
        case 4: {
            double v;
            cout << "Нова вага для DOG: ";
            cin >> v;
            myDog.setVaga(v);
            break;
        }
        case 5: {
            int v;
            cout << "Новий вік для DOG: ";
            cin >> v;
            myDog.setVik(v);
            break;
        }
        case 6: {
            double z;
            cout << "Новий зріст для DOG: ";
            cin >> z;
            myDog.setZrist(z);
            break;
        }
        case 7:
            mySpaniel.druk();
            break;
        case 8:
            myDog.druk();
            break;
        case 9:
            mySpaniel.golos();
            break;
        case 10:
            myDog.golos();
            break;
        case 0:
            cout << "Вихід із програми." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте знову." << endl;
        }

    } while (choice != 0);

    return 0;
}
