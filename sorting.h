#ifndef SORTING_H
#define SORTING_H

#include "employee.h"

void bubbleSort(Employee* employees[], int count) {
    int n = count;
    int swapped;

    do {
        swapped = 0; //0 mean no swap
        for (int i = 0; i < n - 1; i++) {
            if (employees[i]->getSalary() > employees[i + 1]->getSalary()) {
                Employee* temp = employees[i];
                employees[i] = employees[i + 1];
                employees[i + 1] = temp;
                swapped = 1;
            }
        }
        n--;
    } while (swapped != 0);
}

#endif