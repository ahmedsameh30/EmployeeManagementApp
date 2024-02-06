#ifndef VOLUNTEER_H
#define VOLUNTEER_H
#include <StaffMember.h>
#include<iostream>
#include<fstream>
using namespace std;

class Volunteer : public StaffMember
{
private :
    double amount;
    fstream volun;

    char _amount[8];
public :
    Volunteer();
    void read();
    void print();
    void display_employees_withinDepartment(string);
    void update();
    void delete_();
    void search_();
    double pay();
    virtual ~Volunteer();

    protected:
};

#endif // VOLUNTEER_H
