#ifndef BST_H
#define BST_H

#include <iostream>
#include "employee.h"

struct TreeNode {
    Employee* employee;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Employee* emp):employee(emp), left(nullptr), right(nullptr)
};

class CompanyBST : public Company{
private:
    TreeNode* root;

    void insertNode(TreeNode*& node, Employee* emp);
    Employee* findNode(TreeNode* node, const std::string& name);
    void displayInOrder(TreeNode* node);
    void freeTree(TreeNode* node);

public:
    CompanyBST() : root(nullptr) 
    ~CompanyBST() { freeTree(root); }

    void addEmployee(const std::string& name, int experience, double salary);
    Employee* getEmployee(const std::string& name);
    void displayEmployeesInOrder();
};

#endif