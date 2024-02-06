#include "ExecutiveEmployee.h"
#include<windows.h>

ExecutiveEmployee::ExecutiveEmployee():SalariedEmployee(),bonus(0)
{
    //ctor
}

void ExecutiveEmployee::read()
{
    cout<<"---------------------------------------\n";
    cout<<"\n##  Enter the required details\n";
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

    cout<<"\t Enter the salary  : ";
    cin>>salary;

    cout<<"\t Enter the bonus [ '0' if none] : ";
    cin>>bonus;

    cout<<"\t Enter department id : ";
    string id; cin>>id;

    fstream dept;
    bool f = false;

    dept.open("Department.txt",ios::in);
    while(!dept.eof()){
        dept.getline(dept_id,6,'|');
        dept.getline(dept_name,30);

        if(dept_id == id){
            exec.open("Executive Employees.txt",ios::app);
            exec<<employee_id<<'|'<<name<<'|'<<phone<<'|'<<email<<'|'<<SSN<<'|'<<salary<<'|'<<bonus<<'|'<<dept_id<<'\n';
            exec.close();
            f = true;
        }
    }
    dept.close();
    if(!f)
        cout<<"\n\t There are no department with such id ! \n";
}
void ExecutiveEmployee::print()
{
    cout<<"---------------------------------------\n";
    cout<<"## Executive Employees...\n";
    exec.open("Executive Employees.txt",ios::in);
    while(!exec.eof()){
        exec.getline(emp_id,10,'|');
        exec.getline(_name,40,'|');
        exec.getline(_phone,14,'|');
        exec.getline(_email,30,'|');
        exec.getline(ssn,15,'|');
        exec.getline(salry,8,'|');
        exec.getline(bons,7,'|');
        exec.getline(dept_id,6);

        cout<<"\t Employee id :- "<<emp_id<<"\t The name :- "<<_name<<"\n";
        cout<<"\t Phone number :- "<<_phone<<"\t E-mail :- "<<_email<<"\n";
        cout<<"\t The SSN :- "<<ssn<<"\t Department id :- "<<dept_id<<"\n";
        cout<<"\t The salary :- "<<salry<<"\t the bonus :- "<<bons<<"\n\n";
    }
    exec.close();
    cout<<"\n";
}
void ExecutiveEmployee::display_employees_withinDepartment(string ID)
{
    cout<<"---------------------------------------\n";
    cout<<"## Executive Employees...\n";
    exec.open("Executive Employees.txt",ios::in);
    while(!exec.eof()){
        exec.getline(emp_id,10,'|');
        exec.getline(_name,40,'|');
        exec.getline(_phone,14,'|');
        exec.getline(_email,30,'|');
        exec.getline(ssn,15,'|');
        exec.getline(salry,8,'|');
        exec.getline(bons,7,'|');
        exec.getline(dept_id,6);

        if(dept_id == ID){
            cout<<"\t Employee id :- "<<emp_id<<"\t The name :- "<<_name<<"\n";
            cout<<"\t Phone number :- "<<_phone<<"\t E-mail :- "<<_email<<"\n";
            cout<<"\t The SSN :- "<<ssn<<"\t Department id :- "<<dept_id<<"\n";
            cout<<"\t The salary :- "<<salry<<"\t the bonus :- "<<bons<<"\n\n";
        }
    }
    exec.close();
    cout<<"\n";
}
void ExecutiveEmployee::update()
{
    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    string ID; cin>>ID;

    fstream temp;
    bool f = false;

    exec.open("Executive Employees.txt",ios::in);
    temp.open("temp.txt",ios::out);
    int c = 0;
    while(!exec.eof()){
        exec.getline(emp_id,10,'|');
        exec.getline(_name,40,'|');
        exec.getline(_phone,14,'|');
        exec.getline(_email,30,'|');
        exec.getline(ssn,15,'|');
        exec.getline(salry,8,'|');
        exec.getline(bons,7,'|');
        exec.getline(dept_id,6);

        if(emp_id == ID){
            cout<<"\t What do you want to update ?! \n\n";
            cout<<"\t 1. Id\n"
                <<"\t 2. Name\n"
                <<"\t 3. Phone number\n"
                <<"\t 4. E-mail\n"
                <<"\t 5. SSN\n"
                <<"\t 6. Salary\n"
                <<"\t 7. Bonus\n"
                <<"\t 8. Department id\n";
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
                    cout<<"\t Enter the salary : ";
                    cin>>salry;
                    break;
                case 7 :
                    cout<<"\t Enter the bonus : ";
                    cin>>bons;
                    break;
                case 8 :
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
        temp<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<salry<<'|'<<bons<<'|'<<dept_id<<'\n';
    }
    if(!f and c)cout<<"\t There are no employees with such id !\n";
    exec.close();
    temp.close();

    exec.open("Executive Employees.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(emp_id,10,'|');
        temp.getline(_name,40,'|');
        temp.getline(_phone,14,'|');
        temp.getline(_email,30,'|');
        temp.getline(ssn,15,'|');
        temp.getline(salry,8,'|');
        temp.getline(bons,7,'|');
        temp.getline(dept_id,6);

        exec<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<salry<<'|'<<bons<<'|'<<dept_id<<'\n';
    }
    exec.close();
    temp.close();
    remove("temp.txt");
}
void ExecutiveEmployee::delete_()
{
    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    string ID; cin>>ID;

    fstream temp;

    exec.open("Executive Employees.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!exec.eof()){
        exec.getline(emp_id,10,'|');
        exec.getline(_name,40,'|');
        exec.getline(_phone,14,'|');
        exec.getline(_email,30,'|');
        exec.getline(ssn,15,'|');
        exec.getline(salry,8,'|');
        exec.getline(bons,7,'|');
        exec.getline(dept_id,6);

        if(emp_id != ID){
            temp<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<salry<<'|'<<bons<<'|'<<dept_id<<'\n';
        }
    }
    exec.close();
    temp.close();

    exec.open("Executive Employees.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(emp_id,10,'|');
        temp.getline(_name,40,'|');
        temp.getline(_phone,14,'|');
        temp.getline(_email,30,'|');
        temp.getline(ssn,15,'|');
        temp.getline(salry,8,'|');
        temp.getline(bons,7,'|');
        temp.getline(dept_id,6);

        exec<<emp_id<<'|'<<_name<<'|'<<_phone<<'|'<<_email<<'|'<<ssn<<'|'<<salry<<'|'<<bons<<'|'<<dept_id<<'\n';
    }
    exec.close();
    temp.close();
    remove("temp.txt");
}
void ExecutiveEmployee::search_()
{
    cout<<"---------------------------------------\n";
    cout<<"\t Enter employee id :- ";
    string ID; cin>>ID;
    exec.open("Executive Employees.txt",ios::in);
    bool f = false;
    while(!exec.eof()){
        exec.getline(emp_id,10,'|');
        exec.getline(_name,40,'|');
        exec.getline(_phone,14,'|');
        exec.getline(_email,30,'|');
        exec.getline(ssn,15,'|');
        exec.getline(salry,8,'|');
        exec.getline(bons,7,'|');
        exec.getline(dept_id,6);

        if(emp_id == ID){
            f = true;
        }
    }
    exec.close();
    if(f)cout<<"\n\t This employee already exists..\n";
    else cout<<"\n\t Not Found !\n";
}
double ExecutiveEmployee::pay()
{
    double sum = 0.0;
    exec.open("Executive Employees.txt",ios::in);
    while(!exec.eof()){
        exec.getline(emp_id,10,'|');
        exec.getline(_name,40,'|');
        exec.getline(_phone,14,'|');
        exec.getline(_email,30,'|');
        exec.getline(ssn,15,'|');
        exec.getline(salry,8,'|');
        exec.getline(bons,7,'|');
        exec.getline(dept_id,6);

        sum += (charArr_to_int(salry) + charArr_to_int(bons));
    }
    exec.close();
    return sum;
}

ExecutiveEmployee::~ExecutiveEmployee()
{
    //dtor
}
