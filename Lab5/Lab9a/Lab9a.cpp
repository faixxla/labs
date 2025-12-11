#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001");

    int n;

    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Елемент " << i + 1 << ": ";
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    ofstream outFile("results.txt");
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        delete[] arr;
        return 1;
    }

    outFile << "Масив: ";
    for (int i = 0; i < n; ++i) {
        outFile << arr[i] << " ";
    }
    outFile << "\nСума: " << sum << endl;
    outFile.close();

    delete[] arr;

    ifstream inFile("results.txt");
    if (!inFile) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return 1;
    }

    cout << "\nЗчитані дані з файлу:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}