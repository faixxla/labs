#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

class B1 {
protected:
    int x;
public:
    B1(int v);
    virtual void show() const;
    friend std::ostream& operator<<(std::ostream& os, const B1& o);
};

class B2 {
protected:
    int x;
public:
    B2(int v);
    virtual void show() const;
    friend std::ostream& operator<<(std::ostream& os, const B2& o);
};

class B3 {
protected:
    int x;
public:
    B3(int v);
    virtual void show() const;
    friend std::ostream& operator<<(std::ostream& os, const B3& o);
};

class D1 : private B1, public B2, protected virtual B3 {
protected:
    int x;
public:
    D1(int b1, int b2, int b3, int d1);
    virtual void show() const override;
    friend std::ostream& operator<<(std::ostream& os, const D1& o);
};

class D2 : private virtual B3, public D1 {
protected:
    int x;
public:
    D2(int b3, int b1, int b2, int d1, int d2);
    virtual void show() const override;
    friend std::ostream& operator<<(std::ostream& os, const D2& o);
};

class D3 : public virtual B3 {
protected:
    int x;
public:
    D3(int b3, int d3);
    virtual void show() const override;
    friend std::ostream& operator<<(std::ostream& os, const D3& o);
};

class D4 : protected D2 {
protected:
    int x;
public:
    D4(int b3, int b1, int b2, int d1, int d2, int d4);
    virtual void show() const override;
    friend std::ostream& operator<<(std::ostream& os, const D4& o);
};

#endif
