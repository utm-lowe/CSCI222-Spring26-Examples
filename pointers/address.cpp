#include "memviz.h"

int main()
{
    MemViz viz;
    int x;   // an integer
    int *p;  // a pointer to an integer

    x = 10;
    p = &x; 

    *p = 42;

    viz.add("x", &x, sizeof(x));
    viz.add("p", &p, sizeof(p));
    viz.visualize();
}