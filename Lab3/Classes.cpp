#include "Classes.h"

B1::B1(int val) : b1(val) {}
void B1::show() {
    cout << "B1: " << b1 << endl;
}
ostream& operator<<(ostream& out, const B1& obj) {
    return out << "B1: " << obj.b1;
}

B2::B2(int val) : b2(val) {}
void B2::show() {
    cout << "B2: " << b2 << endl;
}
ostream& operator<<(ostream& out, const B2& obj) {
    return out << "B2: " << obj.b2;
}

D1::D1(int val, int b1val, int b2val) : B1(b1val), B2(b2val), d1(val) {}
void D1::show() {
    B1::show();
    B2::show();
    cout << "D1: " << d1 << endl;
}
ostream& operator<<(ostream& out, const D1& obj) {
    out << static_cast<const B1&>(obj) << ", "
        << static_cast<const B2&>(obj) << ", D1: " << obj.d1;
    return out;
}

D2::D2(int val, int b1val, int b2val) : B1(b1val), B2(b2val), d2(val) {}
void D2::show() {
    B1::show();
    B2::show();
    cout << "D2: " << d2 << endl;
}
ostream& operator<<(ostream& out, const D2& obj) {
    out << static_cast<const B1&>(obj) << ", "
        << static_cast<const B2&>(obj) << ", D2: " << obj.d2;
    return out;
}

D3::D3(int val, int d1val, int d2val, int b1val_d1, int b2val_d1, int b1val_d2, int b2val_d2)
    : D1(d1val, b1val_d1, b2val_d1), D2(d2val, b1val_d2, b2val_d2), d3(val) {
}

void D3::show() {
    D1::show();
    D2::show();
    cout << "D3: " << d3 << endl;
}

ostream& operator<<(ostream& out, const D3& obj) {
    out << static_cast<const D1&>(obj) << "\n"
        << static_cast<const D2&>(obj) << "\nD3: " << obj.d3;
    return out;
}
