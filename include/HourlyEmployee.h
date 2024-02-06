#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include<Employee.h>
#include<bits/stdc++.h>
using namespace std;

class HourlyEmployee : public Employee
{
private :
    double workedHours;
    double rate;

    char wor_hour[5];
    char rat[7];

    fstream hourly;
public :
    HourlyEmployee();

    void read();
    void print();
    void display_employees_withinDepartment(string);
    void update();
    void delete_();
    void search_();
    double pay();

    virtual ~HourlyEmployee();

    protected:
};

#endif // HOURLYEMPLOYEE_H
