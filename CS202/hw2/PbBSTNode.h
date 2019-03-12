/**
* Title : Binary Search Trees
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 2
* Description : Header file for pointer based tree node
*/
#include <iostream>
using namespace std;
#ifndef __PBSTNODE_H
#define __PBSTNODE_H
class PbBSTNode{
private :
    int item; // Data portion
    PbBSTNode* leftChildPtr; // Pointer to left child
    PbBSTNode* rightChildPtr; // Pointer to right child
    //default constructor
    PbBSTNode();
    //non-default constructors
    PbBSTNode(const int &newItem);
    PbBSTNode(const int &newItem, PbBSTNode* left, PbBSTNode* right);
    void setItem( const int& newItem);
    int getItem() const;
    bool isLeaf() const ;
    PbBSTNode* getLeftChildPtr() const ;
    PbBSTNode* getRightChildPtr() const ;
    void setLeftChildPtr(PbBSTNode* leftPtr);
    void setRightChildPtr(PbBSTNode* rightPtr);
    friend class PbBST;

};
#endif
