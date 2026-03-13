#include <iostream>

using namespace std;

class C 
{
public:
    C() {
        cout << "No-Arg Constructor" << endl;
    }

    // This is how we should do a copy constructor
    C(const C &other) {
        cout << "Copy Constructor" << endl;
    }

    // This is dangerous. It implies that I alter the other when I copy.
    // This would be a "code smell".
    C(C &other) {
        cout << "Non-Const Copy Constructor" << endl;
    }

    virtual ~C() {
        cout << "Destructor" << endl;
    }


    C& operator=(const C &other)  {
        cout << "Assignment Operator" << endl;
        return *this;
    }
};

void f(C c) {
    cout << "I am in f" << endl;
}


void g(const C &c) {
    cout << "I am in g, calling f" << endl;
    f(c);
    cout << "I am in g, about to return." << endl;
}


int main()
{
    C cobject;
    C dobject(cobject);

    cout << "Calling f" << endl;
    f(cobject);
    cout << "After f" << endl;

    cout << "Calling g" << endl;
    g(cobject);
    cout << "After g" << endl;

    cout << "cobject=dobject" << endl;
    cobject = dobject;
    cout << "cobject=dobject done" << endl;
}