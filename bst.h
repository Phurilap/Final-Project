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

    Employee* findEmployee(TreeNode* node, const std::string& name) const{ 
        if(!node) return nullptr;
        if(name == node->employee->getName()) return node->employee;
        if(name < node->employee->getName()) return findEmployee(node->left, name);
        return findEmployee(node->right, name);
    }

    void displayEmployees(TreeNode* node) const{ 
        if(node){
            displayEmployees(node->left);
            node->employee->display();
            displayEmployees(node->right);
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

    Employee* findEmployee(const std::string& name) const{
        return findEmployee(root, name);
    }

    void displayEmployees() const{  
        displayEmployees(root);
    }
};

#endif