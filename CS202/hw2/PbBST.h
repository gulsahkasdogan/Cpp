/**
* Title : Binary Search Trees
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 2
* Description : Header file for pointer based tree implementation
*/
#include <iostream>
#include "PbBSTNode.h"
#include <cmath>
using namespace std;
#ifndef __PBST_H
#define __PBST_H
class PbBST
{
private :
    PbBSTNode* rootPtr;

    //auxiliary functions will be here-to keep implementation details not-visible
    void copyTree(PbBSTNode* treePtr, PbBSTNode*& newTreePtr)
    {
        //returns the copied trees root pointer
        //treePtr = rootPtr of the tree we want to copy
        //newTreePtr = result tree's rootPtr
        if(treePtr != NULL)
        {
            //preorder traversal
            newTreePtr = new PbBSTNode(treePtr->item);
            copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
            copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
        }
        else
            newTreePtr = NULL;//copy  empty tree
    }
    void destroy(PbBSTNode* nodePtr)
    {
        //this function is used for destructor, it is a recursive function
        //use postorder traverse to delete all items
        if(nodePtr != NULL)
        {
            destroy(nodePtr->leftChildPtr);
            destroy(nodePtr->rightChildPtr);
            delete nodePtr;
            nodePtr = NULL;//avoid dangling pointer
        }

    }

    void insertItem(PbBSTNode*&nodePtr, int key)
    {

        if (nodePtr == NULL)
        {
            nodePtr = new PbBSTNode(key, NULL, NULL);
        }
        // Else search for the insertion position
        else if (key < nodePtr->item)
            insertItem(nodePtr->leftChildPtr, key);
        else
            insertItem(nodePtr->rightChildPtr, key);

    }

    void inorder(PbBSTNode* nodePtr)
    {
        if(nodePtr != NULL)
        {
            inorder(nodePtr->leftChildPtr);
            cout<<" "<<nodePtr->item<<" ";
            inorder(nodePtr->rightChildPtr);
        }
    }

    void preorder(PbBSTNode* nodePtr){
        if(nodePtr != NULL){
            cout<<" "<<nodePtr->item<<" ";
            preorder(nodePtr->leftChildPtr);
            preorder(nodePtr->rightChildPtr);
        }
    }

    void postorder(PbBSTNode* nodePtr){
        if(nodePtr != NULL){
            postorder(nodePtr->leftChildPtr);
            postorder(nodePtr->rightChildPtr);
            cout<<" "<<nodePtr->item<<" ";
        }
    }

    void deleteItem(PbBSTNode*& nodePtr, int key)
    {
        if(nodePtr != NULL)
        {
            if(nodePtr->item == key)
            {
                //item to delete found
                deleteNode(nodePtr);
            }
            else if(nodePtr->item > key)
            {
                //look at the left
                deleteItem(nodePtr->leftChildPtr, key);
            }
            else
            {
                //look at the right
                deleteItem(nodePtr->rightChildPtr, key);
            }
        }
    }

    void deleteNode(PbBSTNode*&nodePtr)
    {
        PbBSTNode* deleteThis;
        int replacementItem;

        if(nodePtr->leftChildPtr == NULL && nodePtr->rightChildPtr == NULL)
        {
            //no children == leaf node
            delete nodePtr;
            nodePtr = NULL;//avoid dangling pointer
        }
        else if(nodePtr->leftChildPtr == NULL)
        {
            //has only right child, no left child
            deleteThis = nodePtr;
            nodePtr = nodePtr->rightChildPtr;
            deleteThis->rightChildPtr = NULL;
            delete deleteThis;
        }
        else if(nodePtr->rightChildPtr == NULL)
        {
            //has only left child, no right child
            deleteThis = nodePtr;
            nodePtr = nodePtr->leftChildPtr;
            deleteThis->leftChildPtr = NULL;
            delete deleteThis;
        }
        else
        {
            //has two children left/right
            //tricky: find the inorder successor of the node you want to delete
            processLeftmost(nodePtr->rightChildPtr, replacementItem);
            nodePtr->item = replacementItem;
        }
    }

    void processLeftmost(PbBSTNode*& nodePtr, int &replacementItem)
    {
        if (nodePtr->leftChildPtr == NULL)
        {
            replacementItem = nodePtr->item;
            PbBSTNode *delPtr = nodePtr;
            nodePtr = nodePtr->rightChildPtr;
            delPtr->rightChildPtr = NULL;
            delete delPtr;
        }
        else
            processLeftmost(nodePtr->leftChildPtr, replacementItem);

    }
    void getNodeCountHelper(PbBSTNode*nodePtr, int &countOfNodes)
    {
        if(nodePtr != NULL)
        {
            countOfNodes++;
            getNodeCountHelper(nodePtr->leftChildPtr, countOfNodes);
            getNodeCountHelper(nodePtr->rightChildPtr, countOfNodes);
        }
    }


    int getHeightHelper(PbBSTNode*nodePtr)
    {
        if(nodePtr == NULL)
        {
            return 0;
        }
        else
        {
            return 1+ max(getHeightHelper(nodePtr->leftChildPtr), getHeightHelper(nodePtr->rightChildPtr));
        }
    }

    bool isLevelFull(int levelNo){
        int nodesInLevel = 0;
        this->isLevelFull(rootPtr, levelNo, nodesInLevel);
        if(nodesInLevel == pow(2, levelNo-1))
            return true;
        else
            return false;
    }

    void isLevelFull(PbBSTNode* nodePtr, int i, int &nodeNumber){
        if(nodePtr != NULL){
            if(i==1)
                nodeNumber++;
            else{
                this->isLevelFull(nodePtr->leftChildPtr, i-1, nodeNumber);
                this->isLevelFull(nodePtr->rightChildPtr, i-1, nodeNumber);
            }
        }
    }

    void swapSiblings(PbBSTNode*&nodePtr){
        if(nodePtr != NULL){
            PbBSTNode *temp = nodePtr->leftChildPtr;
            nodePtr->leftChildPtr = nodePtr->rightChildPtr;
            nodePtr->rightChildPtr = temp;
            if(nodePtr->rightChildPtr != NULL){
                swapSiblings(nodePtr->rightChildPtr);
            }
            if(nodePtr->leftChildPtr != NULL){
               swapSiblings(nodePtr->leftChildPtr);
            }
        }
    }

public:
    //default constructor for binary search tree
    PbBST();
    //non-default constructors for binary search tree
    PbBST( const int& rootItem);
    //constructor that can take two trees for left and right-this is not a copy constructor
    PbBST( const int& rootItem, const PbBST &leftTreePtr, const PbBST &rightTreePtr);
    //copy constructor
    PbBST( const PbBST& tree);
    //Destructor-No idea why this is virtual
    virtual ~PbBST();
    bool isEmpty();
    void attachLeftSubtree(PbBST &leftTree);
    void attachRightSubtree(PbBST &rightTree);
    void insertKey(int key);
    void deleteKey(int key);
    int getHeight();
    int getNodeCount();
    int findNodesRequired();
    int findFullBTLevel();
    void mirrorTree();
    void printTree();
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
};
#endif
