#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include<Employee.h>
#include<iostream>

class CommissionEmployee : public Employee
{
private :
    long target;
    char targ[15];

    fstream comm;
public :

    CommissionEmployee();
    void read();
    void print();
    void display_employees_withinDepartment(string);
    void update();
    void delete_();
    void search_();
    double pay();

    virtual ~CommissionEmployee();

protected:
};

#endif // COMMISSIONEMPLOYEE_H
