#include "employee.h"
#include "employee.h"
#include <iostream>

int main()
{
    Employee e;  // create an employee
    Employee e2("Alice", "Engineering", 9000000);  // create an employee with parameters

    // print out e2's information
    std::cout << "Name: " << e2.getName() << std::endl
                << "Department: " << e2.getDepartment() << std::endl
                << "Salary: $" << e2.getSalary() << std::endl;             
}