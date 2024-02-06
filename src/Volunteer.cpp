#include "Volunteer.h"
#include<windows.h>
using namespace std;

Volunteer::Volunteer():StaffMember(),amount(0.0)
{
    //ctor
}

void Volunteer::read()
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

    cout<<"\t Enter an amount : ";
    cin>>amount;

    cout<<"\t Enter department id : ";
    string id; cin>>id;

    fstream dept;
    bool f = false;

    dept.open("Department.txt",ios::in);
    while(!dept.eof()){
        dept.getline(dept_id,6,'|');
        dept.getline(dept_name,30);

        if(dept_id == id){
            volun.open("Volunteer.txt",ios::app);
            volun<<employee_id<<'|'<<name<<'|'<<phone<<'|'<<email<<'|'<<amount<<'|'<<dept_id<<'\n';
            volun.close();
            f = true;
        }
    }
    dept.close();
    if(!f)
        cout<<"\n\t There are no department with such id ! \n";
}
void Volunteer::print()
{
    cout<<"\n## Volunteer Employees...\n";
    cout<<"---------------------------------------\n";
    volun.open("Volunteer.txt",ios::in);
    while(!volun.eof()){
        volun.getline(emp_id,10,'|');
        volun.getline(_name,40,'|');
        volun.getline(_phone,14,'|');
        volun.getline(_email,30,'|');
        volun.getline(_amount,8,'|');
        volun.getline(dept_id,6);

        string t = emp_id;
        if(t.size() > 0){
            cout<<"\t Employee id :- "<<emp_id<<"\t The name :- "<<_name<<"\n";
            cout<<"\t Phone number :- "<<_phone<<"\t E-mail :- "<<_email<<"\n";
            cout<<"\t The amount :- "<<_amount<<"\t Department id :- "<<dept_id<<"\n\n";
        }
    }
    volun.close();
    cout<<"\n";
}
void Volunteer::display_employees_withinDepartment(string ID)
{
    cout<<"\n## Volunteer Employees...\n";
    cout<<"---------------------------------------\n";
    volun.open("Volunteer.txt",ios::in);
    while(!volun.eof()){
        volun.getline(emp_id,10,'|');
        volun.getline(_name,40,'|');
        volun.getline(_phone,14,'|');
        volun.getline(_email,30,'|');
        volun.getline(_amount,8,'|');
        volun.getline(dept_id,6);

        if(dept_id == ID){
            cout<<"\t Employee id :- "<<emp_id<<"\t The name :- "<<_name<<"\n";
            cout<<"\t Phone number :- "<<_phone<<"\t E-mail :- "<<_email<<"\n";
            cout<<"\t The amount :- "<<_amount<<"\t Department id :- "<<dept_id<<"\n\n";
        }
    }
    volun.close();
    cout<<"\n";
}
void Volunteer::update()
{
    bool f = false;
    string ID;

    cout<<"\n---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    cin>>ID;

    fstream temp;

    volun.open("Volunteer.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!volun.eof()){
        volun.getline(emp_id,10,'|');
        volun.getline(_name,40,'|');
        volun.getline(_phone,14,'|');
        volun.getline(_email,30,'|');
        volun.getline(_amount,8,'|');
        volun.getline(dept_id,6);

        if(emp_id == ID){
            cout<<"\t What do you want to update ?! \n\n";
            cout<<"\t 1. Id\n"
                <<"\t 2. Name\n"
                <<"\t 3. Phone number\n"
                <<"\t 4. E-mail\n"
                <<"\t 5. Amount\n"
                <<"\t 6. Department id\n";
            cout<<"\t Enter your choice : "; int c; cin>>c;
            switch(c)
            {
                case 1 :
                    cout<<"\t Enter id : ";
                    cin.getline(emp_id,10);
                    break;
                case 2 :
                    cout<<"\t Enter name : ";
                    cin.ignore(); cin.getline(_name,40);
                    break;
                case 3 :
                    cout<<"\t Enter phone : ";
                    cin.getline(_phone,14);
                    break;
                case 4 :
                    cout<<"\t Enter email : ";
                    cin.getline(_email,30);
                    break;
                case 5 :
                    cout<<"\t Enter amount : ";
                    cin.getline(_amount,8);
                    break;
                case 6 :
                    cout<<"\t Enter department id : ";
                    cin.getline(dept_id,6);
                    break;
                case 0 :
                    break;
                default :
                    cout<<"\t Invalid choice. please, try again\n";
                    Sleep(3000);
            }
            f = true;
        }
        temp<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<_amount<<'|'<<dept_id<<'\n';
    }
    if(!f)cout<<"\t There are no employees with such id !\n";
    volun.close();
    temp.close();

    volun.open("Volunteer.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(emp_id,10,'|');
        temp.getline(_name,40,'|');
        temp.getline(_phone,14,'|');
        temp.getline(_email,30,'|');
        temp.getline(_amount,8,'|');
        temp.getline(dept_id,6);

        volun<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<_amount<<'|'<<dept_id<<'\n';
    }
    volun.close();
    temp.close();
    remove("temp.txt");
}
void Volunteer::delete_()
{
    string ID;

    cout<<"\n---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    cin>>ID;

    fstream temp;

    volun.open("Volunteer.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!volun.eof()){
        volun.getline(emp_id,10,'|');
        volun.getline(_name,40,'|');
        volun.getline(_phone,14,'|');
        volun.getline(_email,30,'|');
        volun.getline(_amount,8,'|');
        volun.getline(dept_id,6);

        if(emp_id != ID){
            temp<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<_amount<<'|'<<dept_id<<'\n';
        }
    }
    volun.close();
    temp.close();

    volun.open("Volunteer.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(emp_id,10,'|');
        temp.getline(_name,40,'|');
        temp.getline(_phone,14,'|');
        temp.getline(_email,30,'|');
        temp.getline(_amount,8,'|');
        temp.getline(dept_id,6);

        volun<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<_amount<<'|'<<dept_id<<'\n';
    }
    volun.close();
    temp.close();
    remove("temp.txt");
}
void Volunteer::search_()
{
    bool f = false;
    string ID;

    cout<<"\t Enter employee id :- ";
    cin>>ID;

    volun.open("Volunteer.txt",ios::in);
    while(!volun.eof()){
        volun.getline(emp_id,10,'|');
        volun.getline(_name,40,'|');
        volun.getline(_phone,14,'|');
        volun.getline(_email,30,'|');
        volun.getline(_amount,8,'|');
        volun.getline(dept_id,6);

        if(emp_id == ID){
            f = true;
        }
    }
    volun.close();
    if(f)cout<<"\n\t This employee already exists..\n";
    else cout<<"\n\t Not Found !\n";
}
double Volunteer::pay()
{
    double sum = 0.0;

    volun.open("Volunteer.txt",ios::in);
    while(!volun.eof()){
        volun.getline(emp_id,10,'|');
        volun.getline(_name,40,'|');
        volun.getline(_phone,14,'|');
        volun.getline(_email,30,'|');
        volun.getline(_amount,8,'|');
        volun.getline(dept_id,6);

        string tmp = _amount;
        if(tmp.length() > 0)
            sum += charArr_to_int(_amount);
    }
    volun.close();
    return sum;
}

Volunteer::~Volunteer()
{
    //dtor
}
