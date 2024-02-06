#include "HourlyEmployee.h"
#include<windows.h>
using namespace std;

HourlyEmployee::HourlyEmployee():Employee(),workedHours(0.0),rate(0.0)
{
    //ctor
}

void HourlyEmployee::read()
{
    cout<<"---------------------------------------\n";
    cout<<"## Enter the required details\n";

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

    cout<<"\t Enter the number of working hours  : ";
    cin>>workedHours;

    cout<<"\t Enter the rate per hour : ";
    cin>>rate;

    cout<<"\t Enter department id : ";
    string id; cin>>id;

    fstream dept;
    bool f = false;

    dept.open("Department.txt",ios::in);
    while(!dept.eof()){
        dept.getline(dept_id,6,'|');
        dept.getline(dept_name,30);

        if(dept_id == id){
            hourly.open("Hourly Employees.txt",ios::app);
            hourly<<employee_id<<'|'<<name<<'|'<<phone<<'|'<<email<<'|'<<SSN<<'|'<<workedHours<<'|'<<rate<<'|'<<dept_id<<'\n';
            hourly.close();
            f = true;
        }
    }
    dept.close();
    if(!f)
        cout<<"\n\t There are no department with such id ! \n";
}
void HourlyEmployee::print()
{
    cout<<"---------------------------------------\n";
    cout<<"## Hourly Employees...\n";

    hourly.open("Hourly Employees.txt",ios::in);
    while(!hourly.eof()){
        hourly.getline(emp_id,10,'|');
        hourly.getline(_name,40,'|');
        hourly.getline(_phone,14,'|');
        hourly.getline(_email,30,'|');
        hourly.getline(ssn,15,'|');
        hourly.getline(wor_hour,5,'|');
        hourly.getline(rat,7,'|');
        hourly.getline(dept_id,6);

        cout<<"\t Employee id :- "<<emp_id<<"\t The name :- "<<_name<<"\n";
        cout<<"\t Phone number :- "<<_phone<<"\t E-mail :- "<<_email<<"\n";
        cout<<"\t The SSN :- "<<ssn<<"\t Department id :- "<<dept_id<<"\n";
        cout<<"\t The worked hours :- "<<wor_hour<<"\t the rate :- "<<rat<<"\n\n";
    }
    hourly.close();
    cout<<"\n";
}
void HourlyEmployee::display_employees_withinDepartment(string ID)
{
    cout<<"---------------------------------------\n";
    cout<<"## Hourly Employees...\n";

    hourly.open("Hourly Employees.txt",ios::in);
    while(!hourly.eof()){
        hourly.getline(emp_id,10,'|');
        hourly.getline(_name,40,'|');
        hourly.getline(_phone,14,'|');
        hourly.getline(_email,30,'|');
        hourly.getline(ssn,15,'|');
        hourly.getline(wor_hour,5,'|');
        hourly.getline(rat,7,'|');
        hourly.getline(dept_id,6);

        if(dept_id == ID){
            cout<<"\t Employee id :- "<<emp_id<<"\t The name :- "<<_name<<"\n";
            cout<<"\t Phone number :- "<<_phone<<"\t E-mail :- "<<_email<<"\n";
            cout<<"\t The SSN :- "<<ssn<<"\t Department id :- "<<dept_id<<"\n";
            cout<<"\t The worked hours :- "<<wor_hour<<"\t the rate :- "<<rat<<"\n\n";
        }
    }
    hourly.close();
    cout<<"\n";
}
void HourlyEmployee::update()
{
    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    string ID; cin>>ID;

    fstream temp;
    bool f = false;

    hourly.open("Hourly Employees.txt",ios::in);
    temp.open("temp.txt",ios::out);
    int c = 0;
    while(!hourly.eof()){
        hourly.getline(emp_id,10,'|');
        hourly.getline(_name,40,'|');
        hourly.getline(_phone,14,'|');
        hourly.getline(_email,30,'|');
        hourly.getline(ssn,15,'|');
        hourly.getline(wor_hour,5,'|');
        hourly.getline(rat,7,'|');
        hourly.getline(dept_id,6);

        if(emp_id == ID){
            cout<<"\t What do you want to update ?! \n\n";
            cout<<"\t 1. Id\n"
                <<"\t 2. Name\n"
                <<"\t 3. Phone number\n"
                <<"\t 4. E-mail\n"
                <<"\t 5. SSN\n"
                <<"\t 6. Worked Hours\n"
                <<"\t 7. Rate\n"
                <<"\t 8. Department id\n";
            cout<<"\t Enter your choice : "; cin>>c;
            switch(c)
            {
                case 1 :
                    cout<<"\t Enter id : "; cin>>emp_id;
                    break;
                case 2 :
                    cout<<"\t Enter name : ";
                    cin.ignore(), cin.getline(_name,14);
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
                    cout<<"\t Enter SSN : ";
                    cin.getline(ssn,15);
                    break;
                case 6 :
                    cout<<"\t Enter worked hours : ";
                    cin.getline(wor_hour,5);
                    break;
                case 7 :
                    cout<<"\t Enter rate : ";
                    cin.getline(rat,7);
                    break;
                case 8 :
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
        temp<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<wor_hour<<'|'<<rat<<'|'<<dept_id<<'\n';
    }
    if(!f and c)cout<<"\t There are no employees with such id !\n";
    hourly.close();
    temp.close();

    hourly.open("Hourly Employees.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(emp_id,10,'|');
        temp.getline(_name,40,'|');
        temp.getline(_phone,14,'|');
        temp.getline(_email,30,'|');
        temp.getline(ssn,15,'|');
        temp.getline(wor_hour,5,'|');
        temp.getline(rat,7,'|');
        temp.getline(dept_id,6);

        hourly<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<wor_hour<<'|'<<rat<<'|'<<dept_id<<'\n';
    }
    hourly.close();
    temp.close();
    remove("temp.txt");
}
void HourlyEmployee::delete_()
{
    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    string ID; cin>>ID;

    fstream temp;

    hourly.open("Hourly Employees.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!hourly.eof()){
        hourly.getline(emp_id,10,'|');
        hourly.getline(_name,40,'|');
        hourly.getline(_phone,14,'|');
        hourly.getline(_email,30,'|');
        hourly.getline(ssn,15,'|');
        hourly.getline(wor_hour,5,'|');
        hourly.getline(rat,7,'|');
        hourly.getline(dept_id,6);

        if(emp_id != ID){
            temp<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<wor_hour<<'|'<<rat<<'|'<<dept_id<<'\n';
        }
    }
    hourly.close();
    temp.close();

    hourly.open("Hourly Employees.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(emp_id,10,'|');
        temp.getline(_name,40,'|');
        temp.getline(_phone,14,'|');
        temp.getline(_email,30,'|');
        temp.getline(ssn,15,'|');
        temp.getline(wor_hour,5,'|');
        temp.getline(rat,7,'|');
        temp.getline(dept_id,6);

        hourly<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<wor_hour<<'|'<<rat<<'|'<<dept_id<<'\n';
    }
    hourly.close();
    temp.close();
    remove("temp.txt");
}
void HourlyEmployee::search_()
{
    bool f = false;
    string ID;

    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    cin>>ID;

    hourly.open("Hourly Employees.txt",ios::in);
    while(!hourly.eof()){
        hourly.getline(emp_id,10,'|');
        hourly.getline(_name,40,'|');
        hourly.getline(_phone,14,'|');
        hourly.getline(_email,30,'|');
        hourly.getline(ssn,15,'|');
        hourly.getline(wor_hour,5,'|');
        hourly.getline(rat,7,'|');
        hourly.getline(dept_id,6);

        if(emp_id == ID){
            f = true;
        }
    }
    hourly.close();
    if(f)cout<<"\n\t This employee already exists..\n";
    else cout<<"\n\t Not Found !\n";
}
double HourlyEmployee::pay()
{
    double sum = 0.0;
    hourly.open("Hourly Employees.txt",ios::in);
    while(!hourly.eof()){
        hourly.getline(emp_id,10,'|');
        hourly.getline(_name,40,'|');
        hourly.getline(_phone,14,'|');
        hourly.getline(_email,30,'|');
        hourly.getline(ssn,15,'|');
        hourly.getline(wor_hour,5,'|');
        hourly.getline(rat,7,'|');
        hourly.getline(dept_id,6);

        sum += (charArr_to_int(wor_hour)*charArr_to_int(rat));
    }
    hourly.close();
    return sum;
}

HourlyEmployee::~HourlyEmployee()
{
    //dtor
}
