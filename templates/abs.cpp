#include <iostream>
using namespace std;

// a function template which computes absolute value
template<typename T> T myabs(T x) 
{
    if(x < 0) {
        return -x;
    }

    return x;
}


int main()
{
    int x;
    double y;

    cout << "Give me an integer: ";
    cin >> x;
    cout << "Abs: " << myabs(x) << endl;

    cout << "Give me a double: ";
    cin >> y;
    cout << "Abs: " << myabs(y) << endl;
    cout << "Int Abs: " << myabs<int>(y) << endl;
    cout << "Char Abs: " << myabs<char>(y) << endl;
}