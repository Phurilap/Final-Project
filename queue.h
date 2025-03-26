#ifndef QUEUE_H
#define QUEUE_H

#include "employee.h"
using namespace std;

class Queue {
private:
    Employee** candidates;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int cap = 10){
        capacity = cap;
        candidates = new Employee*[capacity];
        front = 0;
        rear = 0;
        count = 0;
    }

    ~Queue(){
        for(int i = 0; i < count; i++){
            int index = (front + i) % capacity;
            delete candidates[index];
        }
        delete[] candidates;
    }

    void enqueue(Employee* candidate){
        if(count < capacity){
            candidates[rear] = candidate;
            rear = (rear + 1) % capacity;
            count++;
        } else{
            cout<<"Queue is full."<<endl;
        }
    }

    Employee* dequeue(){
        if(count > 0){
            Employee* candidate = candidates[front];
            front = (front + 1) % capacity;
            count--;
            return candidate;
        } else{
            cout<<"Queue is empty."<<endl;
            return nullptr;
        }
    }

    bool isEmpty() const{
        return count == 0;
    }
};

#endif