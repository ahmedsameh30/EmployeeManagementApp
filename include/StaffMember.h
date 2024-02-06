#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H
#include<bits/stdc++.h>
using namespace std;

class StaffMember
{
protected :
    int employee_id;
    string name;
    string phone;
    string email;

    char emp_id[10];
    char _name[40];
    char _phone[14];
    char _email[30];
    char dept_id[6];
    char dept_name[30];

public :
    StaffMember();
    virtual void read() = 0;
    virtual void print() = 0;
    virtual void display_employees_withinDepartment(string) = 0;
    virtual void update() = 0;
    virtual void delete_() = 0;
    virtual void search_() = 0;
    virtual double pay() = 0;
    double charArr_to_int(string);
    virtual ~StaffMember();
private:

};

#endif // STAFFMEMBER_H
