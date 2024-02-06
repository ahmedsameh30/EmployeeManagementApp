#include<iostream>
#include<cstdlib>
#include<windows.h>
#include "Department.h"
#include "Staff.h"
#include "Project.h"

using namespace std;

void department()
{
    int c = 1;
    Department dept;
    while(c != 0)
    {
        cout<<"\n=================================================\n";
        cout<<"\t [1] Add new department\n"
            <<"\t [2] Print all departments\n"
            <<"\t [0] Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                dept.read();
                break;
            case 2 :
                dept.print();
                Sleep(10000);
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
void handle_staff()
{
    Staff stf;
    int c = 1;
    while(c != 0)
    {
        cout<<"\n=================================================\n";
        cout<<"\t [1] Add new member\n"
            <<"\t [2] Display...\n"
            <<"\t [3] Edit Member\n"
            <<"\t [4] Calculate total Payroll\n"
            <<"\t [5] Search for member\n"
            <<"\t [6] Delete member\n"
            <<"\t [0] Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                stf.add_member();
                break;
            case 2 :
                stf.print();
                break;
            case 3 :
                stf.update_member_data();
                break;
            case 4 :
                stf.Calculate_total_payroll();
                break;
            case 5 :
                stf.search_for_member();
                break;
            case 6 :
                stf.delete_member();
                break;
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
void project()
{
    Project proj;
    int c = 1;
    while(c != 0)
    {
        cout<<"\n=================================================\n";
        cout<<"\t [1] Add New Project\n"
            <<"\t [2] Print All Projects\n"
            <<"\t [3] Print a specific project details\n"
            <<"\t [4] Add Budget to Existing Project\n"
            <<"\t [5] Increase Budget to Existing Project\n"
            <<"\t [0] Exit\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                proj.add_project();
                break;
            case 2 :
                proj.display_projects_details();
                break;
            case 3 :
                proj.dispaly_a_specific_project();
                break;
            case 4 :
                proj.add_budget();
                break;
            case 5 :
                proj.increase_budget_to_existing_project();
            case 0 :
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
void employee_management()
{
    int c = 1;
    while(c != 0){
        system("cls");
        cout<<"\t Where are you want to go ?! \n\n";
        cout<<"\t [1] Department file.\n"
            <<"\t [2] Staff file.\n"
            <<"\t [3] Project file.\n"
            <<"\t [0] Exit.\n";
        cout<<"\t Enter your choice : "; cin>>c;
        switch(c)
        {
            case 1 :
                department();
                break;
            case 2 :
                handle_staff();
                break;
            case 3 :
                project();
                break;
            case 0 :
                cout<<"\n\n\t\t Thanks..\n\n";
                break;
            default :
                cout<<"\t Invalid choice. please, try again\n";
                Sleep(3000);
        }
    }
}
int main()
{
    employee_management();
    return 0;
}
