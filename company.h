#ifndef COMPANY_H
#define COMPANY_H

#include "employee.h"
#include "sorting.h"
#include <iostream>
using namespace std;

class Company {
private:
    Employee** employees;
    int capacity;
    int count;
public:
    Company(int cap = 10) : capacity(cap), count(0) {
        employees = new Employee*[capacity];
    }

    ~Company() {
        for (int i = 0; i < count; i++) {
            delete employees[i];
        }
        delete[] employees;
    }

    void addEmployee(const string &name, int exp, double sal) {
        if (count >= capacity) {
            cout << "No more space for new employees." << endl;
            return;
        }
        employees[count++] = new Employee(name, sal, exp);
    }

    void displayEmployees() const {
        for (int i = 0; i < count; i++) {
            employees[i]->display();
        }
    }

    void sortEmployees() {
        bubbleSort(employees, count);
    }

    Employee* getEmployee(int index){
        if(index >= 0 && index < count){
            return employees[index];
        }
        return nullptr;
    }
};

#endif