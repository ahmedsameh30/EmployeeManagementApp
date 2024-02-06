#ifndef PROJECT_H
#define PROJECT_H
#include "Budget.h"
#include<bits/stdc++.h>
using namespace std;

class Project
{
private :
    string project_id;
    string manager_id;
    string location;
    string current_cost;
    string type;

    Budget budget;
    fstream proj;

    char _project_id[10];
    char _manager_id[10];
    char _location[30];
    char _current_cost[20];
    char _type[20];

    long charArr_to_int(string&);
    void update_the_current_cost(string&,long&);

public :
    Project();

    void handle(string);
    void add_project();
    void add_budget();
    void dispaly_a_specific_project();
    void display_projects_details();
    void increase_budget_to_existing_project();

    virtual ~Project();

protected:
};

#endif // PROJECT_H
