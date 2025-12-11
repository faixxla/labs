#include "Classes.h"

int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001");
    D3 obj(100, 10, 20, 1, 2, 3, 4);

    cout << "--- Метод show() ---" << endl;
    obj.show();

    cout << "\n--- Оператор << ---" << endl;
    cout << obj << endl;

    return 0;
}
