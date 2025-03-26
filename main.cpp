#include <iostream>
#include <cstdlib>
#include "company.h"


int main(int argc, char* argv[]){
    Company myCompany;

    for(int i = 1; i < argc; i+=3){
        string name = argv[i];
        int experience = atoi(argv[i+1]);
        double salary = atof(argv[i+2]);
        myCompany.addEmployee(name, experience, salary);
    }

    cout<<"\nEmployees before sorting:\n";
    myCompany.displayEmployees();
    cout<<endl;

    Employee* emp = myCompany.getEmployee(1);
    if(emp){
        cout<<"Updating experience and salary for "<<emp->getName()<<endl;
        *emp+= 4500;
        ++(*emp);
    }

    cout<<"\nEmployees after new updates:\n";
    myCompany.displayEmployees();
    cout<<endl;

    myCompany.sortEmployees();
    cout<<"\nEmployees after sorting(by salary):\n";
    myCompany.displayEmployees();
    cout<<endl;
    return 0;
}
