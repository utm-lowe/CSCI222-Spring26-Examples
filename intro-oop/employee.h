#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
public:
    Employee();
    Employee(const std::string &name, const std::string &department, int salary);
   
    std::string getName();
    std::string getDepartment();
    int getSalary();

    // mutators
    void setName(const std::string &name);
    void setDepartment(const std::string &department);
    void setSalary(int salary);
       
private:
    std::string name;
    std::string department;
    int salary;
};
#endif