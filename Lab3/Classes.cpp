#include "classes.h"

B1::B1(int v) : x(v) {}
void B1::show() const { std::cout << "B1: " << x << "\n"; }
std::ostream& operator<<(std::ostream& os, const B1& o) { return os << "B1(" << o.x << ")"; }

B2::B2(int v) : x(v) {}
void B2::show() const { std::cout << "B2: " << x << "\n"; }
std::ostream& operator<<(std::ostream& os, const B2& o) { return os << "B2(" << o.x << ")"; }

B3::B3(int v) : x(v) {}
void B3::show() const { std::cout << "B3: " << x << "\n"; }
std::ostream& operator<<(std::ostream& os, const B3& o) { return os << "B3(" << o.x << ")"; }

D1::D1(int b1, int b2, int b3, int d1)
    : B1(b1), B2(b2), B3(b3), x(d1) {
}

void D1::show() const {
    std::cout << "D1: " << x << "\n";
    B1::show();
    B2::show();
    B3::show();
}

std::ostream& operator<<(std::ostream& os, const D1& o) { return os << "D1(" << o.x << ")"; }

D2::D2(int b3, int b1, int b2, int d1, int d2)
    : B3(b3), D1(b1, b2, b3, d1), x(d2) {
}

void D2::show() const {
    std::cout << "D2: " << x << "\n";
    D1::show();
}

std::ostream& operator<<(std::ostream& os, const D2& o) { return os << "D2(" << o.x << ")"; }

D3::D3(int b3, int d3) : B3(b3), x(d3) {}

void D3::show() const {
    std::cout << "D3: " << x << "\n";
    B3::show();
}

std::ostream& operator<<(std::ostream& os, const D3& o) { return os << "D3(" << o.x << ")"; }

D4::D4(int b3, int b1, int b2, int d1, int d2, int d4)
    : B3(b3), D2(b3, b1, b2, d1, d2), x(d4) {
}

void D4::show() const {
    std::cout << "D4: " << x << "\n";
    D2::show();
}

std::ostream& operator<<(std::ostream& os, const D4& o) { return os << "D4(" << o.x << ")"; }
