#include "Tasks.h"
#include <fstream>
using namespace std;
long double VectorTask::dotProduct(const vector<long double>& a, const vector<long double>& b) {
    if (a.size() != b.size()) {
        throw invalid_argument("Різна довжина векторів для скалярного добутку.");
    }
    long double acc = 0.0L;
    auto itA = a.begin();
    auto itB = b.begin();
    for (; itA != a.end(); ++itA, ++itB) {
        acc += (*itA) * (*itB);
    }
    return acc;
}

void VectorTask::runFromFile(const string& path) {
    ifstream fin(path);
    if (!fin) throw runtime_error("Не вдалося відкрити файл: " + path);

    size_t n{};
    if (!(fin >> n)) throw runtime_error("Очікувався розмір n.");

    vector<long double> a; 
    a.reserve(n);
    vector<long double> b; 
    b.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        long double x{};
        if (!(fin >> x)) throw runtime_error("Некоректні дані першого вектора.");
        a.push_back(x);
    }
    for (size_t i = 0; i < n; ++i) {
        long double x{};
        if (!(fin >> x)) throw runtime_error("Некоректні дані другого вектора.");
        b.push_back(x);
    }

    long double res = dotProduct(a, b);
    cout << "Скалярний добуток = " << res << "\n";
}

void ListTask::eraseFirstAndLast(list<long long>& L) {
    if (L.empty()) throw runtime_error("Список порожній.");
    if (L.size() == 1) throw runtime_error("У списку лише один елемент.");
    L.pop_front();
    L.pop_back();
}

void ListTask::printList(const list<long long>& L) {
    bool first = true;
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (!first) cout << ' ';
        cout << *it;
        first = false;
    }
    cout << "\n";
}

void ListTask::runFromFile(const string& path) {
    ifstream fin(path);
    if (!fin) throw runtime_error("Не вдалося відкрити файл: " + path);

    size_t m{};
    if (!(fin >> m)) throw runtime_error("Очікувався розмір m.");

    list<long long> L;
    for (size_t i = 0; i < m; ++i) {
        long long x{};
        if (!(fin >> x)) throw runtime_error("Некоректний елемент списку.");
        L.push_back(x);
    }

    eraseFirstAndLast(L);
    cout << "Список після видалення першого та останнього:\n";
    printList(L);
}

vector<string> MapTask::findFailed(const map<string, string>& mp) {
    vector<string> res;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        const string& grade = it->second;
        if (grade == "F" || grade == "0") {
            res.push_back(it->first);
        }
    }
    return res;
}

void MapTask::printAll(const map<string, string>& mp) {
    cout << "Усі записи (ім'я -> оцінка):\n";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << "  " << it->first << " -> " << it->second << "\n";
    }
}

void MapTask::runFromFile(const string& path) {
    ifstream fin(path);
    if (!fin) throw runtime_error("Не вдалося відкрити файл: " + path);

    size_t k{};
    if (!(fin >> k)) throw runtime_error("Очікувалась кількість записів k.");

    map<string, string> mp;
    for (size_t i = 0; i < k; ++i) {
        string name, grade;
        if (!(fin >> name >> grade)) throw runtime_error("Некоректний запис (ім'я/оцінка).");
        mp.insert(make_pair(name, grade));
    }

    printAll(mp);
    auto failed = findFailed(mp);
    if (failed.empty()) {
        cout << "Студентів, які НЕ склали, не знайдено.\n";
    }
    else {
        cout << "Не склали предмет: ";
        for (size_t i = 0; i < failed.size(); ++i) {
            if (i) cout << ", ";
            cout << failed[i];
        }
        cout << "\n";
    }
}
