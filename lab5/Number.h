#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Number {
private:
    T value;

public:
    Number() : value(T()) {}
    Number(T v) : value(v) {}
    void print() const {
        std::cout << value << std::endl;
    }
    Number<T>& operator=(const Number<T>& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }
    template <typename U>
    auto operator+(const Number<U>& other) const -> decltype(value + other.getValue()) {
        return value + other.getValue();
    }
    T getValue() const { return value; }
};

#endif
