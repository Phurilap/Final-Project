#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;
    int experience;

public:
    //constructor
    Employee(string = "", double = 0.0, int = 0);
    //destructor
    ~Employee();
    //getter
    string getName();
    double getSalary();
    int getExperience();    
    //operator things
    void operator++();
    void operator+=(double);
    void display();
};

//set function
Employee::Employee(string n, double s, int e){
    name = n;
    salary = s;
    experience = e;
    cout<<"Employee "<<name<<" created"<<endl;
}

Employee::~Employee(){
    cout<<"Employee "<<name<<" removed"<<endl;
}

string Employee::getName(){
    return name;
}

double Employee::getSalary(){
    return salary;
}

int Employee::getExperience(){
    return experience;
}

void Employee::operator++(){
    experience++;
}

void Employee::operator+=(double amt){
    salary+= amt;
}

void Employee::display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Salary: "<<salary<<" Baht"<<endl;
    cout<<"Experience "<<experience<<" Years"<<endl;
}

#endif