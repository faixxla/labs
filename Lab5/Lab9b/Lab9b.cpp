#include <iostream>
#include <fstream>

using namespace std;
int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001");

    const char* filename = "numbers.bin";

    {
        ofstream fout(filename, ios::binary);
        if (!fout) {
            cerr << "Помилка створення файлу.\n";
            return 1;
        }

        int number;
        cout << "Введіть 10 цілих чисел:\n";
        for (int i = 0; i < 10; ++i) {
            cout << i + 1 << ": ";
            cin >> number;
            fout.write(reinterpret_cast<const char*>(&number), sizeof(int));
        }
    }

    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл.\n";
        return 1;
    }

    int number;

    file.seekg(4 * sizeof(int), ios::beg);
    file.read(reinterpret_cast<char*>(&number), sizeof(int));

    if (number % 2 == 0) {
        number = 77;
        for (int i = 0; i < 4; ++i) {
            file.seekp(i * sizeof(int), ios::beg);
            file.write(reinterpret_cast<const char*>(&number), sizeof(int));
        }
    }
    else {
        number = 88;
        for (int i = 5; i < 10; ++i) {
            file.seekp(i * sizeof(int), ios::beg);
            file.write(reinterpret_cast<const char*>(&number), sizeof(int));
        }
    }

    file.close();

    ifstream fin(filename, ios::binary);
    cout << "\nЧисла у файлі після обробки:\n";
    for (int i = 0; i < 10; ++i) {
        fin.read(reinterpret_cast<char*>(&number), sizeof(int));
        cout << number << " ";
    }
    cout << "\n";

    return 0;
}
