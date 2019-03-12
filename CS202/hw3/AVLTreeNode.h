/**
* Title : AVL Tree Node
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 3
* Description : Header file for AVL Node
*/
#include <iostream>
using namespace std;
#ifndef __AVLTREENODE_H
#define __AVLTREENODE_H
class AVLTreeNode{
private:
    int item; // Data portion
    AVLTreeNode* leftChildPtr; // Pointer to left child
    AVLTreeNode* rightChildPtr; // Pointer to right child
    int balanceFactor;
    int height;

    //default constructor
    AVLTreeNode();
    //non-default constructors
    AVLTreeNode(const int &newItem);
    AVLTreeNode(const int &newItem, AVLTreeNode* left, AVLTreeNode* right);
    //copy constructor
    AVLTreeNode(const AVLTreeNode &node);
    void operator=(const AVLTreeNode &node );
    void setItem( const int& newItem);
    int getItem() const;
    bool isLeaf() const ;
    AVLTreeNode* getLeftChildPtr() const ;
    AVLTreeNode* getRightChildPtr() const ;
    void setLeftChildPtr(AVLTreeNode* leftPtr);
    void setRightChildPtr(AVLTreeNode* rightPtr);
    friend class AVLTree;
    friend class Stack;
};
#endif
