#include <iostream>
using namespace std;

class B1 {
protected:
    int b1;
public:
    B1(int val) : b1(val) {
    }

    virtual void show() {
        cout << "B1: " << b1 << endl;
    }

    friend ostream& operator<<(ostream& out, const B1& obj) {
        return out << "B1: " << obj.b1;
    }

};

class B2 {
protected:
    int b2;
public:
    B2(int val) : b2(val) {
    }

    virtual void show() {
        cout << "B2: " << b2 << endl;
    }

    friend ostream& operator<<(ostream& out, const B2& obj) {
        return out << "B2: " << obj.b2;
    }

};

class D1 : virtual public B1, virtual public B2 {
protected:
    int d1;
public:
    D1(int val, int b1val, int b2val)
        : B1(b1val), B2(b2val), d1(val) {
    }

    void show() override {
        B1::show();
        B2::show();
        cout << "D1: " << d1 << endl;
    }

    friend ostream& operator<<(ostream& out, const D1& obj) {
        out << static_cast<const B1&>(obj) << ", "
            << static_cast<const B2&>(obj) << ", D1: " << obj.d1;
        return out;
    }
};

class D2 : virtual public B1, virtual public B2 {
protected:
    int d2;
public:
    D2(int val, int b1val, int b2val)
        : B1(b1val), B2(b2val), d2(val) {
    }

    void show() override {
        B1::show();
        B2::show();
        cout << "D2: " << d2 << endl;
    }

    friend ostream& operator<<(ostream& out, const D2& obj) {
        out << static_cast<const B1&>(obj) << ", "
            << static_cast<const B2&>(obj) << ", D2: " << obj.d2;
        return out;
    }
};

class D3 : public D1, public D2 {
    int d3;
public:
    D3(int val, int d1val, int d2val, int b1val, int b2val)
        : B1(b1val), B2(b2val), D1(d1val, b1val, b2val), D2(d2val, b1val, b2val), d3(val) {
    }

    void show() override {
        D1::show();
        D2::show();
        cout << "D3: " << d3 << endl;
    }

    friend ostream& operator<<(ostream& out, const D3& obj) {
        out << static_cast<const D1&>(obj) << "\n"
            << static_cast<const D2&>(obj) << "\nD3: " << obj.d3;
        return out;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    system("chcp 65001");

    D3 obj(100, 10, 20, 1, 2);

    cout << "\n--- Метод show() ---" << endl;
    obj.show();

    cout << "\n--- Оператор << ---" << endl;
    cout << obj << endl;

    return 0;
}
