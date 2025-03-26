#include <iostream>
#include <cstdlib>
#include "company.h"

int main(int argc, char* argv[]){
    Company myCompany;

    for(int i = 1; i < argc; i += 3){
        string name = argv[i];
        int experience = atoi(argv[i+1]);
        double salary = atof(argv[i+2]);
        myCompany.addEmployee(name, experience, salary);
    }

    //Display in BST order
    cout<<"\nEmployees BST order:\n";
    myCompany.displayEmployeesBST();

    //Display original array
    cout<<"\nEmployees original order:\n";
    myCompany.displayEmployeesArray();

    //Sort and display by salary
    myCompany.sortEmployeesBySalary();
    cout<<"\nEmployees sorted by salary:\n";
    myCompany.displayEmployeesArray();

    //Employee update
    Employee* emp = myCompany.getEmployee(1);
    if(emp){
        cout<<"\nUpdating experience and salary for "<<emp->getName()<<endl;
        *emp += 4500;
        ++(*emp);
        emp->display();
    }

    //BST search
    string searchName = argv[1];
    Employee* found = myCompany.findEmployee(searchName);
    if(found){
        cout<<"\nFound via BST search:\n";
        found->display();
    }

    //Process queue
    cout<<"\nProcessing candidate queue:\n";
    while(myCompany.hasCandidates()){
        Employee* candidate = myCompany.processNextCandidate();
        cout<<"Processed: "<<candidate->getName()<<endl;
    }

    return 0;
}