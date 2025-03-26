#ifndef BST_H
#define BST_H

#include <iostream>
#include "employee.h"

struct TreeNode {
    Employee* employee;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Employee* emp) : employee(emp), left(nullptr), right(nullptr) {}
};

class CompanyBST {
private:
    TreeNode* root;

    void insertNode(TreeNode*& node, Employee* emp){
        if(!node){
            node = new TreeNode(emp);
        } else if(emp->getName() < node->employee->getName()){
            insertNode(node->left, emp);
        } else{
            insertNode(node->right, emp);
        }
    }

    Employee* findNode(TreeNode* node, const std::string& name){
        if(!node) return nullptr;
        if(name == node->employee->getName()) return node->employee;
        if(name < node->employee->getName()) return findNode(node->left, name);
        return findNode(node->right, name);
    }

    void displayInOrder(TreeNode* node){
        if(node){
            displayInOrder(node->left);
            node->employee->display();
            displayInOrder(node->right);
        }
    }

    void freeTree(TreeNode* node){
        if(node){
            freeTree(node->left);
            freeTree(node->right);
            delete node;
        }
    }

public:
    CompanyBST() : root(nullptr) {}
    ~CompanyBST() { freeTree(root); }

    void addEmployee(Employee* emp){
        insertNode(root, emp);
    }

    Employee* getEmployee(const std::string& name){
        return findNode(root, name);
    }

    void displayEmployeesInOrder(){
        displayInOrder(root);
    }
};

#endif