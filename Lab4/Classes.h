#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
using namespace std;

class B1 {
protected:
    int b1;
public:
    B1(int val);
    virtual void show();
    friend ostream& operator<<(ostream& out, const B1& obj);
};

class B2 {
protected:
    int b2;
public:
    B2(int val);
    virtual void show();
    friend ostream& operator<<(ostream& out, const B2& obj);
};

class D1 : private B1, public B2 {
protected:
    int d1;
public:
    D1(int val, int b1val, int b2val);
    void show() override;
    friend ostream& operator<<(ostream& out, const D1& obj);
};

class D2 : public B1, private B2 {
protected:
    int d2;
public:
    D2(int val, int b1val, int b2val);
    void show() override;
    friend ostream& operator<<(ostream& out, const D2& obj);
};

class D3 : private D1, public D2 {
    int d3;
public:
    D3(int val, int d1val, int d2val, int b1val_d1, int b2val_d1, int b1val_d2, int b2val_d2);
    void show() override;
    friend ostream& operator<<(ostream& out, const D3& obj);
};

#endif
