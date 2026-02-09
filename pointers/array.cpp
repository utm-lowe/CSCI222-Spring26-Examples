#include "memviz.h"
#include <iostream>
#include <iomanip>

using namespace std;

void sprint(char *s) 
{
    while(*s) {
        cout << *s++;
    }
}

int main()
{
    char s[] = "Hello, world\n";
    int ar[10];
    MemViz viz;
    
    viz.add("s", s, sizeof(s));
    viz.add("ar", ar, sizeof(ar));

    viz.visualize();

    cout << dec << "sizeof(s)=" << (int) sizeof(s) << endl; 
    cout << dec << "sizeof(ar)=" << (int) sizeof(ar) << endl; 
    cout << dec << "sizeof(int)=" << (int) sizeof(int) << endl; 
    cout << dec << "sizeof(float)=" << (float) sizeof(float) << endl; 
    cout << dec << "sizeof(double)=" << (double) sizeof(double) << endl; 
    cout << "Elements in ar: " << sizeof(ar) / sizeof(ar[0]) << endl;
    cout << "Elements in s: " << sizeof(s) / sizeof(s[0]) << endl;
    sprint(s);
}