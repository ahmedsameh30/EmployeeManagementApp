#include "StaffMember.h"
using namespace std;

StaffMember::StaffMember():employee_id(0),name(""),phone(""),email("")
{
    //ctor
}

double StaffMember::charArr_to_int(string sal)
{
    double res = 0.0;
    if(sal == "")
        return res;
    if(sal.find('.') != string::npos){
        string t1 = sal.substr(0,sal.find('.'));
        string t2 = sal.substr(sal.find('.')+1);
        res = stoi(t1) + (stoi(t2)/100.00);
    }
    else{
        res = stoi(sal);
    }
    return res;
}
StaffMember::~StaffMember()
{
    //dtor
}
