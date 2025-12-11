#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <utility>
using namespace std;

template <typename T>
class NumericBox {
private:
    T value{};
public:
    NumericBox() noexcept : value{} {}
    explicit NumericBox(const T& v) : value(v) {}
    void print(ostream& os = cout) const { os << value; }
    const T& get() const noexcept { return value; }
    NumericBox& operator=(const NumericBox& other) noexcept {
        if (this != &other) value = other.value;
        return *this;
    }

    template <typename U, typename = enable_if_t<is_arithmetic<U>::value>>
    NumericBox& operator=(const NumericBox<U>& other) {
        value = static_cast<T>(other.get());
        return *this;
    }

    template <typename U, typename = enable_if_t<is_arithmetic<U>::value>>
    auto operator+(const NumericBox<U>& rhs) const {
        using R = decltype(declval<T>() + declval<U>());
        return NumericBox<R>(static_cast<R>(value) + static_cast<R>(rhs.get()));
    }

    friend ostream& operator<<(ostream& os, const NumericBox& nb) {
        nb.print(os);
        return os;
    }
};

class VectorTask {
public:
    static void runFromFile(const string& path);
private:
    static long double dotProduct(const vector<long double>& a,
        const vector<long double>& b);
};

class ListTask {
public:
    static void runFromFile(const string& path);
private:
    static void eraseFirstAndLast(list<long long>& L);
    static void printList(const list<long long>& L);
};

class MapTask {
public:
    static void runFromFile(const string& path);
private:
    static vector<string> findFailed(const map<string, string>& mp);
    static void printAll(const map<string, string>& mp);
};

#endif
