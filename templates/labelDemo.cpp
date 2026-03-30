#include <iostream>
#include "label.h"

void prompt(Label<int> &l)
{
    std::cout << "Give me a value for " << l.getLabel() << ": ";
    std::cin >> l;
}

int main()
{
    Label<int> a("A");
    Label<int> b("B");
    Label<int> sum("Sum");

    prompt(a);
    prompt(b);

    sum = a + b;
    std::cout << sum << std::endl;
}