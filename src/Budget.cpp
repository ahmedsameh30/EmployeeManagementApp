#include "Budget.h"
#include<bits/stdc++.h>
using namespace std;

Budget::Budget():id(""),value(0)
{
    //ctor
}

long Budget::read(string proj_id)
{
    cout<<"\t Enter budget id : ";
    cin>>id;

    cout<<"\t Enter budget value : ";
    cin>>value;

    budg.open("Budgets.txt",ios::app);
    budg<<proj_id<<'|'<<id<<'|'<<value<<'\n';
    budg.close();
    return value;
}
void Budget::display(string proj_id)
{
    int cnt = 0;
    budg.open("Budgets.txt",ios::in);
    while(!budg.eof()){
        budg.getline(proj_id_,10,'|');
        budg.getline(_id,10,'|');
        budg.getline(_value,10);

        if(proj_id == proj_id_){
            cout<<"\n\t Budget number "<<++cnt<<" :- \n"
                <<"\t Budget id :"<<_id<<"\t Budget value : "<<_value<<endl;
        }
    }
    budg.close();
}
int Budget::increase_bubget(string &ID)
{
    int cost = 0;
    bool f = false;
    fstream temp;

    cout<<"\t Enter budget id : ";
    cin>>id;

    budg.open("Budgets.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!budg.eof()){
        budg.getline(proj_id_,10,'|');
        budg.getline(_id,10,'|');
        budg.getline(_value,10);

        if(ID == proj_id_ and id == _id){
            cout<<"\t Enter the extra cost : ";
            cin>>cost;
            string t = _value;
            int budget_after_update = cost + stoi(t);
            temp<<proj_id_<<'|'<<_id<<'|'<<budget_after_update<<'\n';
            f = true;
        }
        else{
            temp<<proj_id_<<'|'<<_id<<'|'<<_value<<'\n';
        }
    }
    budg.close();
    temp.close();

    if(!f)
        cout<<"\n\t Wrong ! .. Either project id or budget id is invalid\n";

    budg.open("Budgets.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(proj_id_,10,'|');
        temp.getline(_id,10,'|');
        temp.getline(_value,10);

        string t = proj_id_;
        if(t != "")
            budg<<proj_id_<<'|'<<_id<<'|'<<_value<<'\n';
    }
    budg.close();
    temp.close();
    remove("temp.txt");
    return cost;
}

Budget::~Budget()
{
    //dtor
}
