#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <Employee.h>


class SalariedEmployee : public Employee
{
protected :
    double salary;
    char salry[8];

public :

    SalariedEmployee();
    virtual void read() = 0;
    virtual void print() = 0;
    virtual void display_employees_withinDepartment(string) = 0;
    virtual void update() = 0;
    virtual void delete_() = 0;
    virtual void search_() = 0;
    virtual double pay() = 0;

    virtual ~SalariedEmployee();

    private:
};

#endif // SALARIEDEMPLOYEE_H
