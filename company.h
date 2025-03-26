#ifndef COMPANY_H
#define COMPANY_H

#include "employee.h"
#include "queue.h"
#include "bst.h"
#include "sorting.h"
#include <iostream>
using namespace std;

class Company {
private:
    Employee** employees;
    CompanyBST employeeBST;
    Queue candidateQueue;
    int capacity;
    int count;

public:
    Company(int cap = 10) : capacity(cap), count(0) {
        employees = new Employee*[capacity];
    }

    ~Company() {
        for(int i = 0;i < count; i++){
            delete employees[i];
        }
        delete[] employees;
    }

    void addEmployee(const string &name, int exp, double sal){
        if(count >= capacity){
            cout<<"No more space for new employees."<<endl;
            return;
        }
        Employee* emp = new Employee(name, sal, exp);
        employees[count++] = emp;
        employeeBST.addEmployee(emp);
        candidateQueue.enqueue(emp);
    }

    void displayEmployeesArray() const{
        for(int i = 0; i < count; i++){
            employees[i]->display();
        }
    }

    void displayEmployeesBST() const{
        employeeBST.displayEmployeesInOrder();
    }

    void sortEmployeesBySalary(){
        bubbleSort(employees, count);
    }

    Employee* getEmployee(int index){
        if(index >= 0 && index<count){
            return employees[index];
        }
        return nullptr;
    }

    Employee* findEmployee(const string& name){
        return employeeBST.getEmployee(name);
    }

    Employee* processNextCandidate(){
        return candidateQueue.dequeue();
    }

    bool hasCandidates() const{
        return !candidateQueue.isEmpty();
    }
};

#endif