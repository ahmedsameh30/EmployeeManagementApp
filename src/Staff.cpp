#include "Staff.h"
#include<cstdlib>
#include<windows.h>

using namespace std;

Staff::Staff()
{
    staff = nullptr;
}
void Staff::handle_pointer()
{
    delete staff;
    staff = nullptr;
}

// this function displays all employees in the system;
void Staff::display_all_members()
{
    staff = new Volunteer();
    staff->print();
    handle_pointer();

    staff = new HourlyEmployee();
    staff->print();
    handle_pointer();

    staff = new ExecutiveEmployee();
    staff->print();
    handle_pointer();

    staff = new CommissionEmployee();
    staff->print();
    handle_pointer();
}

// This function only displays employees who are
// working in a particular department regardless
// of their classification such as commission, executive, etc..
void Staff::display_employees_within_department()
{
    cout<<"\t Enter department id : ";
    string id; cin>>id;

    staff = new Volunteer();
    staff->display_employees_withinDepartment(id);
    handle_pointer();

    staff = new HourlyEmployee();
    staff->display_employees_withinDepartment(id);
    handle_pointer();

    staff = new ExecutiveEmployee();
    staff->display_employees_withinDepartment(id);
    handle_pointer();

    staff = new CommissionEmployee();
    staff->display_employees_withinDepartment(id);
    handle_pointer();
}

// this function displays specific type of employees.
void Staff::display_specific_category()
{
    int c = 1;
    while(c != 0)
    {
        cout<<"---------------------------------------\n\n";
        cout<<"## Choose the employee type..\n\n";
        cout<<"\t 1. Volunteer\n"
            <<"\t 2. Hourly\n"
            <<"\t 3. Executive\n"
            <<"\t 4. Commission\n"
            <<"\t 0. Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                staff = new Volunteer();
                staff->print();
                handle_pointer();
                break;
            case 2 :
                staff = new HourlyEmployee();
                staff->print();
                handle_pointer();
                break;
            case 3 :
                staff = new ExecutiveEmployee();
                staff->print();
                handle_pointer();
                break;
            case 4 :
                staff = new CommissionEmployee();
                staff->print();
                handle_pointer();
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}


void Staff::add_member()
{
    int c = 1;
    while(c != 0)
    {
        cout<<"---------------------------------------\n";
        cout<<"## Choose the employee type..\n\n";
        cout<<"\t 1. Volunteer\n"
            <<"\t 2. Hourly\n"
            <<"\t 3. Executive\n"
            <<"\t 4. Commission\n"
            <<"\t 0. Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                staff = new Volunteer();
                staff->read();
                handle_pointer();
                break;
            case 2 :
                staff = new HourlyEmployee();
                staff->read();
                handle_pointer();
                break;
            case 3 :
                staff = new ExecutiveEmployee();
                staff->read();
                handle_pointer();
                break;
            case 4 :
                staff = new CommissionEmployee();
                staff->read();
                handle_pointer();
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
void Staff::print()
{
    int c = 1;
    while(c != 0)
    {
        cout<<"---------------------------------------\n";
        cout<<"## What would you like to display ?! \n\n";
        cout<<"\t 1. All employees who are registered on the system\n"
            <<"\t 2. Only the employees who belong to a specific department\n"
            <<"\t 3. A specific category of employees (Hourly - Executive - etc..)\n"
            <<"\t 0. Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                display_all_members();
                break;
            case 2 :
                display_employees_within_department();
                break;
            case 3 :
                display_specific_category();
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
void Staff::delete_member()
{
    int c = 1;
    while(c != 0)
    {
        cout<<"---------------------------------------\n\n";
        cout<<"## Choose the employee type..\n\n";
        cout<<"\t 1. Volunteer\n"
            <<"\t 2. Hourly\n"
            <<"\t 3. Executive\n"
            <<"\t 4. Commission\n"
            <<"\t 0. Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                staff = new Volunteer();
                staff->delete_();
                handle_pointer();
                break;
            case 2 :
                staff = new HourlyEmployee();
                staff->delete_();
                handle_pointer();
                break;
            case 3 :
                staff = new ExecutiveEmployee();
                staff->delete_();
                handle_pointer();
                break;
            case 4 :
                staff = new CommissionEmployee();
                staff->delete_();
                handle_pointer();
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
void Staff::search_for_member()
{
    int c = 1;
    while(c != 0)
    {
        cout<<"---------------------------------------\n\n";
        cout<<"## Choose the employee type..\n\n";
        cout<<"\t 1. Volunteer\n"
            <<"\t 2. Hourly\n"
            <<"\t 3. Executive\n"
            <<"\t 4. Commission\n"
            <<"\t 0. Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                staff = new Volunteer();
                staff->search_();
                handle_pointer();
                break;
            case 2 :
                staff = new HourlyEmployee();
                staff->search_();
                handle_pointer();
                break;
            case 3 :
                staff = new ExecutiveEmployee();
                staff->search_();
                handle_pointer();
                break;
            case 4 :
                staff = new CommissionEmployee();
                staff->search_();
                handle_pointer();
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
void Staff::update_member_data()
{
    int c = 1;
    while(c != 0)
    {
        cout<<"---------------------------------------\n\n";
        cout<<"## Choose the employee type..\n\n";
        cout<<"\t 1. Volunteer\n"
            <<"\t 2. Hourly\n"
            <<"\t 3. Executive\n"
            <<"\t 4. Commission\n"
            <<"\t 0. Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                staff = new Volunteer();
                staff->update();
                handle_pointer();
                break;
            case 2 :
                staff = new HourlyEmployee();
                staff->update();
                handle_pointer();
                break;
            case 3 :
                staff = new ExecutiveEmployee();
                staff->update();
                handle_pointer();
                break;
            case 4 :
                staff = new CommissionEmployee();
                staff->update();
                handle_pointer();
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
void Staff::Calculate_total_payroll()
{
    long double sum = 0;
    staff = new Volunteer();
    sum += staff->pay();
    handle_pointer();

    staff = new HourlyEmployee();
    sum += staff->pay();
    handle_pointer();

    staff = new ExecutiveEmployee();
    sum += staff->pay();
    handle_pointer();

    staff = new CommissionEmployee();
    sum += staff->pay();
    handle_pointer();

    cout<<"\t The total payroll for all employees is :- "<<fixed<<setprecision(4)<<sum<<endl;
}

Staff::~Staff()
{
    if(staff != nullptr)
        handle_pointer();
}
