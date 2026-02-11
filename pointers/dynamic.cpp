#include "memviz.h"
#include <iostream>

using namespace std;

// returns a sequence of numbers
// the returned array is dynamically allocated
int* seq(int start, int end) 
{
    int *ar = nullptr;
    int n = end-start+1;

    ar = new int[n];
    for(int i=0; i<n; i++) {
        ar[i] = start + i;
    }

    return ar;
}

int main()
{
    int *p = nullptr;
    int *ar = nullptr;
    int x;

    MemViz viz;    
    p = new int; // create an integer
    *p = 12;

    ar = seq(1, 5);

    viz.add("p", &p, sizeof(p));
    viz.add("*p", p, sizeof(*p));
    viz.add("ar", &ar, sizeof(ar));
    viz.add("ar[]", ar, sizeof(int) * 5);
    viz.visualize();

    // let's leak some memory
    double *p2=nullptr;
    for(;;) {
        p2 = new double;
    }

    delete p; // destroy an integer
    delete[] ar; // destroy an array
}