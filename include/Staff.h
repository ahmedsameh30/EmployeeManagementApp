#ifndef STAFF_H
#define STAFF_H
#include "StaffMember.h"
#include "Volunteer.h"
#include "HourlyEmployee.h"
#include "ExecutiveEmployee.h"
#include "CommissionEmployee.h"
#include<iostream>
using namespace std;

class Staff
{
private :
    StaffMember *staff;

    void handle_pointer();
    void display_all_members();
    void display_employees_within_department();
    void display_specific_category();

public :
    Staff();
    void add_member();
    void print();
    void delete_member();
    void search_for_member();
    void update_member_data();
    void Calculate_total_payroll();
    virtual ~Staff();

protected:
};

#endif // STAFF_H
