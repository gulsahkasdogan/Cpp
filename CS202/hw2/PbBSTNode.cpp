/**
* Title : Binary Search Trees
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 2
* Description : CPP file for pointer based tree node
*/
#include <iostream>
using namespace std;
#include "PbBSTNode.h"

    //default constructor
    PbBSTNode::PbBSTNode(){
        item = -1; //default?
        leftChildPtr = NULL;
        rightChildPtr = NULL;
    }
    //non-default constructors
    PbBSTNode::PbBSTNode(const int &newItem){
        item = newItem;
        leftChildPtr = NULL;
        rightChildPtr = NULL;
    }

    PbBSTNode::PbBSTNode(const int &newItem, PbBSTNode* left, PbBSTNode* right){
        item = newItem;
        leftChildPtr = left;
        rightChildPtr = right;
    }

    void PbBSTNode::setItem( const int& newItem){
        item = newItem;
    }

    int PbBSTNode::getItem() const {
        return item;
    }

    bool PbBSTNode::isLeaf() const {
        if(leftChildPtr == NULL && rightChildPtr == NULL)
            return true;
        else
            return false;
    }

    PbBSTNode* PbBSTNode::getLeftChildPtr() const{
        return leftChildPtr;
    }

    PbBSTNode* PbBSTNode::getRightChildPtr() const{
        return rightChildPtr;
    }

    void PbBSTNode::setLeftChildPtr(PbBSTNode* leftPtr){
        leftChildPtr = leftPtr;
    }

    void PbBSTNode::setRightChildPtr(PbBSTNode* rightPtr){
        rightChildPtr = rightPtr;
    }
