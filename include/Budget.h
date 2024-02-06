#ifndef BUDGET_H
#define BUDGET_H
#include<bits/stdc++.h>
using namespace std;

class Budget
{
private :
    string id;
    long value;

    char proj_id_[10];
    char _id[10];
    char _value[10];

    fstream budg;
public :

    Budget();
    long read(string);
    void display(string);
    int increase_bubget(string&);
    virtual ~Budget();

protected:
};

#endif // BUDGET_H
