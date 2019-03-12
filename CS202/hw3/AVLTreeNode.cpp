/**
* Title : AVL Tree Node
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 3
* Description : CPP file for AVL Node
*/
#include <iostream>
using namespace std;
#include "AVLTreeNode.h"

    //default constructor
    AVLTreeNode::AVLTreeNode(){
        item = -1; //default?
        leftChildPtr = NULL;
        rightChildPtr = NULL;
        balanceFactor = 0;
        height = 1;
    }
    //non-default constructors
    AVLTreeNode::AVLTreeNode(const int &newItem){
        item = newItem;
        leftChildPtr = NULL;
        rightChildPtr = NULL;
        balanceFactor = 0;
        height = 1;
    }

    AVLTreeNode::AVLTreeNode(const int &newItem, AVLTreeNode* left, AVLTreeNode* right){
        item = newItem;
        leftChildPtr = left;
        rightChildPtr = right;
        balanceFactor = 0;
        height = 1;
    }

    AVLTreeNode::AVLTreeNode(const AVLTreeNode &node){
        item = node.item;
        leftChildPtr = node.leftChildPtr;
        rightChildPtr = node.rightChildPtr;
        balanceFactor = node.balanceFactor;
        height = node.height;
    }

    void AVLTreeNode::operator=(const AVLTreeNode &node){
        item = node.item;
        leftChildPtr = node.leftChildPtr;
        rightChildPtr = node.rightChildPtr;
        balanceFactor = node.balanceFactor;
        height = node.height;
    }

    void AVLTreeNode::setItem( const int& newItem){
        item = newItem;
    }

    int AVLTreeNode::getItem() const {
        return item;
    }

    bool AVLTreeNode::isLeaf() const {
        if(leftChildPtr == NULL && rightChildPtr == NULL)
            return true;
        else
            return false;
    }

    AVLTreeNode* AVLTreeNode::getLeftChildPtr() const{
        return leftChildPtr;
    }

    AVLTreeNode* AVLTreeNode::getRightChildPtr() const{
        return rightChildPtr;
    }

    void AVLTreeNode::setLeftChildPtr(AVLTreeNode* leftPtr){
        leftChildPtr = leftPtr;
    }

    void AVLTreeNode::setRightChildPtr(AVLTreeNode* rightPtr){
        rightChildPtr = rightPtr;
    }
