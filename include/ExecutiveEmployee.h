#ifndef EXECUTIVEEMPLOYEE_H
#define EXECUTIVEEMPLOYEE_H
#include<SalariedEmployee.h>
#include<bits/stdc++.h>
using namespace std;

class ExecutiveEmployee : public SalariedEmployee
{
private :
    int bonus;
    char bons[7];

    fstream exec;
public :
    ExecutiveEmployee();
    void read();
    void print();
    void display_employees_withinDepartment(string);
    void update();
    void delete_();
    void search_();
    double pay();

    virtual ~ExecutiveEmployee();

protected :
};

#endif // EXECUTIVEEMPLOYEE_H
