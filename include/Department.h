#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Department
{
private :
    string id;
    string name;

    fstream depart;

    // for reading from file..
    char _id[6];
    char _name[30];
public :
    Department();
    Department(string,string);
    void read();
    void print();
    virtual ~Department();

protected:
};

#endif // DEPARTMENT_H
