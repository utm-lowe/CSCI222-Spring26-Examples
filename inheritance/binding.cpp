class A {
public:
    virtual int f() {
        return 0;
    }

    int g() {
        return 7;
    }
};


class B : public A {
public:
    int f() override {
        return 42;
    }

    int f(int x) override {
        return x;
    }

    int g() {
        return 8;
    }
};


int f() {
    return 42;
}

int main() {
    f();

    A a;
    a.f();
    a.g();

    B b;
    b.f();
    b.g();

    A *p;
    p = &a;
    p->f();
    p->g();
    p = &b;
    p->f();
    p->g();
}