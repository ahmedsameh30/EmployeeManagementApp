#include "Project.h"
#include<fstream>
using namespace std;

Project::Project():project_id(""),manager_id(""),location(""),current_cost(""),type("")
{
    //ctor
}

long Project::charArr_to_int(string& val)
{
    return stoi(val);
}
void Project::update_the_current_cost(string &proj_id,long &new_budg)
{
    fstream temp;
    proj.open("Projects.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!proj.eof()){
        proj.getline(_project_id,10,'|');
        proj.getline(_location,30,'|');
        proj.getline(_current_cost,20,'|');
        proj.getline(_manager_id,10,'|');
        proj.getline(_type,20);

        string t = _project_id;
        if(proj_id == _project_id and t != ""){
            string tmp = _current_cost;
            long res = charArr_to_int(tmp) + new_budg;
            temp<<_project_id<<'|'<<_location<<'|'<<res<<'|'<<_manager_id<<'|'<<_type<<'\n';
        }
        else{
            temp<<_project_id<<'|'<<_location<<'|'<<_current_cost<<'|'<<_manager_id<<'|'<<_type<<'\n';
        }
    }
    proj.close();
    temp.close();

    proj.open("Projects.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(_project_id,10,'|');
        temp.getline(_location,30,'|');
        temp.getline(_current_cost,20,'|');
        temp.getline(_manager_id,10,'|');
        temp.getline(_type,20);

        string t = _project_id;
        if(t != "")
            proj<<_project_id<<'|'<<_location<<'|'<<_current_cost<<'|'<<_manager_id<<'|'<<_type<<'\n';
    }
    proj.close();
    temp.close();
    remove("temp.txt");
}

void Project::add_project()
{
    cout<<"---------------------------------------\n";
    cout<<"##  Enter the required details\n\n";
    cout<<"\t Enter the project id : ";
    cin>>project_id;

    cout<<"\t Enter the location : ";
    cin.ignore(); getline(cin,location);

    cout<<"\t Enter the current cost of the project : ";
    cin>>current_cost;

    cout<<"\t Enter the manager id : ";
    cin>>manager_id;

    cout<<"\t Enter the manager type : ";
    cin>>type;

    proj.open("Projects.txt",ios::app);
    proj<<project_id<<'|'<<location<<'|'<<current_cost<<'|'<<manager_id<<'|'<<type<<'\n';
    proj.close();
}
void Project::add_budget()
{
    long new_budget = 0;
    bool f = false;

    cout<<"\t Enter the project id : ";
    cin>>project_id;

    proj.open("Projects.txt",ios::in);
    while(!proj.eof()){
        proj.getline(_project_id,10,'|');
        proj.getline(_location,30,'|');
        proj.getline(_current_cost,20,'|');
        proj.getline(_manager_id,10,'|');
        proj.getline(_type,20);

        if(project_id == _project_id){
            new_budget = budget.read(project_id);
            f = true;
        }
    }
    proj.close();
    if(!f)cout<<"\t There is no such id for existing projects\n\n";
    else{
        update_the_current_cost(project_id,new_budget);
    }
}
void Project::dispaly_a_specific_project()
{
    bool f = false;
    cout<<"\t Enter the project id : ";
    cin>>project_id;

    proj.open("Projects.txt",ios::in);
    while(!proj.eof()){
        proj.getline(_project_id,10,'|');
        proj.getline(_location,30,'|');
        proj.getline(_current_cost,20,'|');
        proj.getline(_manager_id,10,'|');
        proj.getline(_type,20);

        if(project_id == _project_id){
            cout<<"\n----------------------------------------------------\n";
            cout<<"\t Project id : "<<_project_id<<"\t Manager id : "<<_manager_id<<"\n";
            cout<<"\t Location : "<<_location<<"\t Current cost : "<<_current_cost<<"\n";
            budget.display(project_id);
            f = true;
        }
    }
    proj.close();
    if(!f)cout<<"\t There is no such id for existing projects\n\n";
}
void Project::display_projects_details()
{
    int cnt = 0;
    proj.open("Projects.txt",ios::in);
    while(!proj.eof()){
        proj.getline(_project_id,10,'|');
        proj.getline(_location,30,'|');
        proj.getline(_current_cost,20,'|');
        proj.getline(_manager_id,10,'|');
        proj.getline(_type,20);

        string tmp = _project_id;
        if(tmp != ""){
            cout<<"----------------------------------------------------\n";
            cout<<"## Project "<<++cnt<<endl;
            cout<<"\t Project id : "<<_project_id<<"\t Manager id : "<<_manager_id<<"\n";
            cout<<"\t Location : "<<_location<<"\t Current cost : "<<_current_cost<<"\n";
            budget.display(_project_id);
        }
    }
    proj.close();
}
void Project::increase_budget_to_existing_project()
{
    cout<<"\n\t Enter project id : ";
    cin>>project_id;
    long extra = budget.increase_bubget(project_id);
    if(extra)
        update_the_current_cost(project_id,extra);
}

Project::~Project()
{
    //dtor
}
