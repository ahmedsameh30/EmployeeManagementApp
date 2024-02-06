#include "Department.h"
using namespace std;

Department::Department()
{

}
Department::Department(string _id,string _name):id(_id),name(_name)
{

}
void Department::read()
{
    cout<<"\t Enter department id : "; cin>>id;
    cout<<"\t Enter department name : "; cin.ignore(); getline(cin,name);
    depart.open("Department.txt",ios::app);
    depart<<id<<'|'<<name<<'\n';
    depart.close();
}
void Department::print()
{
    depart.open("Department.txt",ios::in);
    while(!depart.eof()){
        depart.getline(_id,6,'|');
        depart.getline(_name,30);

        id = _id;
        if(id.length() > 0){
            cout<<"\t Department id :- "<<_id<<"\t Department name :- "<<_name<<endl;
        }
        else break;
    }
    depart.close();
}
Department::~Department()
{
    //dtor
}
