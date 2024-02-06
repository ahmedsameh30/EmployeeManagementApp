#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<StaffMember.h>
#include<string>
using namespace std;


class Employee : public StaffMember
{
protected :
    string SSN;

    char ssn[15];
public :
    Employee();
    virtual void read() = 0;
    virtual void print() = 0;
    virtual void display_employees_withinDepartment(string) = 0;
    virtual void update() = 0;
    virtual void delete_() = 0;
    virtual void search_() = 0;
    virtual double pay() = 0;
    virtual ~Employee();

private :
};

#endif // EMPLOYEE_H
