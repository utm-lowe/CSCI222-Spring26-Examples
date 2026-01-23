#include "memviz.h"

int main()
{
    char s[] = "Hello, world";
    MemViz viz;
    
    viz.add("s", s, sizeof(s));

    viz.visualize();
}