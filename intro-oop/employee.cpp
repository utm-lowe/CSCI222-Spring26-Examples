#include "employee.h"

// Default constructor
Employee::Employee() : name(""), department(""), salary(0)
{
}

// Parameterized constructor
Employee::Employee(const std::string &name, const std::string &department, int salary)
    : name(name), department(department), salary(salary)
{
}

// Getters
std::string Employee::getName()
{
    return name;
}

std::string Employee::getDepartment()
{
    return department;
}

int Employee::getSalary()
{
    return salary;
}

// Setters
void Employee::setName(const std::string &name)
{
    this->name = name;
}

void Employee::setDepartment(const std::string &department)
{
    this->department = department;
}

void Employee::setSalary(int salary)
{
    this->salary = salary;
}
