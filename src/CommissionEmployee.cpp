#include "CommissionEmployee.h"
#include<windows.h>
using namespace std;

CommissionEmployee::CommissionEmployee():Employee(),target(0.0)
{
    //ctor
}

void CommissionEmployee::read()
{
    cout<<"---------------------------------------\n";
    cout<<"##  Enter the required details\n";
    cout<<"\t Enter id : ";
    cin>>employee_id;

    cout<<"\t Enter name : ";
    cin.ignore(); getline(cin,name);

    cout<<"\t Enter phone number : ";
    cin.ignore(); cin>>phone;

    cout<<"\t Enter Email : ";
    cin.ignore(); cin>>email;

    cout<<"\t Enter the social security number : ";
    cin>>SSN;

    cout<<"\t Enter the target : ";
    cin>>target;

    cout<<"\t Enter department id : ";
    string id; cin>>id;

    fstream dept;
    bool f = false;

    dept.open("Department.txt",ios::in);
    while(!dept.eof()){
        dept.getline(dept_id,6,'|');
        dept.getline(dept_name,30);

        if(dept_id == id){
            comm.open("Commission Employees.txt",ios::app);
            comm<<employee_id<<'|'<<name<<'|'<<phone<<'|'<<email<<'|'<<SSN<<'|'<<target<<'|'<<dept_id<<'\n';
            comm.close();
            f = true;
        }
    }
    dept.close();
    if(!f)
        cout<<"\n\t There are no department with such id ! \n";
}
void CommissionEmployee::print()
{
    cout<<"---------------------------------------\n";
    cout<<"## Commission Employees...\n";
    comm.open("Commission Employees.txt",ios::in);
    while(!comm.eof()){
        comm.getline(emp_id,10,'|');
        comm.getline(_name,40,'|');
        comm.getline(_phone,14,'|');
        comm.getline(_email,30,'|');
        comm.getline(ssn,15,'|');
        comm.getline(targ,15,'|');
        comm.getline(dept_id,6);

        cout<<"\t Employee id :- "<<emp_id<<"\t The name :- "<<_name<<"\n";
        cout<<"\t Phone number :- "<<_phone<<"\t E-mail :- "<<_email<<"\n";
        cout<<"\t The SSN :- "<<ssn<<"\t Department id :- "<<dept_id<<"\n";
        cout<<"\t The target :- "<<targ<<"\n\n";
    }
    comm.close();
    cout<<"\n";
}
void CommissionEmployee::display_employees_withinDepartment(string ID)
{
    cout<<"---------------------------------------\n";
    cout<<"## Commission Employees...\n";
    comm.open("Commission Employees.txt",ios::in);
    while(!comm.eof()){
        comm.getline(emp_id,10,'|');
        comm.getline(_name,40,'|');
        comm.getline(_phone,14,'|');
        comm.getline(_email,30,'|');
        comm.getline(ssn,15,'|');
        comm.getline(targ,15,'|');
        comm.getline(dept_id,6);

        if(dept_id == ID){
            cout<<"\t Employee id :- "<<emp_id<<"\t The name :- "<<_name<<"\n";
            cout<<"\t Phone number :- "<<_phone<<"\t E-mail :- "<<_email<<"\n";
            cout<<"\t The SSN :- "<<ssn<<"\t Department id :- "<<dept_id<<"\n";
            cout<<"\t The target :- "<<targ<<"\n\n";
        }
    }
    comm.close();
    cout<<"\n";
}
void CommissionEmployee::update()
{
    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    string ID; cin>>ID;

    bool f = false;
    fstream temp;

    comm.open("Commission Employees.txt",ios::in);
    temp.open("temp.txt",ios::out);
    int c = 0;
    while(!comm.eof()){
        comm.getline(emp_id,10,'|');
        comm.getline(_name,40,'|');
        comm.getline(_phone,14,'|');
        comm.getline(_email,30,'|');
        comm.getline(ssn,15,'|');
        comm.getline(targ,15,'|');
        comm.getline(dept_id,6);

        if(emp_id == ID){
            cout<<"\t What do you want to update ?! \n\n";
            cout<<"\t 1. Id\n"
                <<"\t 2. Name\n"
                <<"\t 3. Phone number\n"
                <<"\t 4. E-mail\n"
                <<"\t 5. SSN\n"
                <<"\t 6. Target\n"
                <<"\t 7. Department id\n";
            cout<<"\t Enter your choice : "; cin>>c;
            switch(c)
            {
                case 1 :
                    cout<<"\t Enter id : ";
                    cin>>emp_id;
                    break;
                case 2 :
                    cout<<"\t Enter name : ";
                    cin.ignore(), cin.getline(_name,40);
                    break;
                case 3 :
                    cout<<"\t Enter phone : ";
                    cin>>_phone;
                    break;
                case 4 :
                    cout<<"\t Enter email : ";
                    cin>>_email;
                    break;
                case 5 :
                    cout<<"\t Enter the SSN : ";
                    cin>>ssn;
                    break;
                case 6 :
                    cout<<"\t Enter the target : ";
                    cin>>targ;
                    break;
                case 7 :
                    cout<<"\t Enter department id : ";
                    cin>>dept_id;
                    break;
                case 0 :
                    break;
                default :
                    cout<<"\t Invalid choice. please, try again\n";
                    Sleep(3000);
            }
            f = true;
        }
        temp<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<targ<<'|'<<dept_id<<'\n';
    }
    if(!f and c)cout<<"\t There are no employees with such id !\n";
    comm.close();
    temp.close();

    comm.open("Commission Employees.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(emp_id,10,'|');
        temp.getline(_name,40,'|');
        temp.getline(_phone,14,'|');
        temp.getline(_email,30,'|');
        temp.getline(ssn,15,'|');
        temp.getline(targ,15,'|');
        temp.getline(dept_id,6);

        comm<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<targ<<'|'<<dept_id<<'\n';
    }
    comm.close();
    temp.close();
    remove("temp.txt");
}
void CommissionEmployee::delete_()
{
    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    string ID; cin>>ID;

    fstream temp;

    comm.open("Commission Employees.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!comm.eof()){
        comm.getline(emp_id,10,'|');
        comm.getline(_name,40,'|');
        comm.getline(_phone,14,'|');
        comm.getline(_email,30,'|');
        comm.getline(ssn,15,'|');
        comm.getline(targ,15,'|');
        comm.getline(dept_id,6);

        if(emp_id != ID){
            temp<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<targ<<'|'<<dept_id<<'\n';
        }
    }
    comm.close();
    temp.close();

    comm.open("Commission Employees.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(emp_id,10,'|');
        temp.getline(_name,40,'|');
        temp.getline(_phone,14,'|');
        temp.getline(_email,30,'|');
        temp.getline(ssn,15,'|');
        temp.getline(targ,15,'|');
        temp.getline(dept_id,6);

        comm<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<targ<<'|'<<dept_id<<'\n';
    }
    comm.close();
    temp.close();
    remove("temp.txt");
}
void CommissionEmployee::search_()
{
    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    string ID; cin>>ID;
    bool f = false;
    comm.open("Commission Employees.txt",ios::in);
    while(!comm.eof()){
        comm.getline(emp_id,10,'|');
        comm.getline(_name,40,'|');
        comm.getline(_phone,14,'|');
        comm.getline(_email,30,'|');
        comm.getline(ssn,15,'|');
        comm.getline(targ,15,'|');
        comm.getline(dept_id,6);

        if(emp_id == ID){
            f = true;
        }
    }
    comm.close();
    if(f)cout<<"\n\t This employee already exists..\n";
    else cout<<"\n\t Not Found !\n";
}
double CommissionEmployee::pay()
{
    double sum = 0.0;
    comm.open("Commission Employees.txt",ios::in);
    while(!comm.eof()){
        comm.getline(emp_id,10,'|');
        comm.getline(_name,40,'|');
        comm.getline(_phone,14,'|');
        comm.getline(_email,30,'|');
        comm.getline(ssn,15,'|');
        comm.getline(targ,15,'|');
        comm.getline(dept_id,6);

        sum += (0.05 * charArr_to_int(targ));
    }
    comm.close();
    return sum;
}

CommissionEmployee::~CommissionEmployee()
{
    //dtor
}
