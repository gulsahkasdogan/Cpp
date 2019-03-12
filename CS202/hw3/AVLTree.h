/**
* Title : AVL tree
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 3
* Description : Header file for AVL
*/
#include <iostream>
#include "AVLTreeNode.h"
#include <cmath>
using namespace std;
#ifndef __AVLTREE_H
#define __AVLTREE_H
class AVLTree
{
private :
    AVLTreeNode* rootPtr;
    bool shorter;

    //auxiliary functions will be here-to keep implementation details not-visible
    void copyTree(AVLTreeNode* treePtr, AVLTreeNode*& newTreePtr)
    {
        //returns the copied trees root pointer
        //treePtr = rootPtr of the tree we want to copy
        //newTreePtr = result tree's rootPtr
        if(treePtr != NULL)
        {
            //preorder traversal
            newTreePtr = new AVLTreeNode(treePtr->item);
            copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
            copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
        }
        else
            newTreePtr = NULL;//copy  empty tree
    }
    void destroy(AVLTreeNode* nodePtr)
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

    void insertItem(AVLTreeNode*&nodePtr, int key)
    {
        if (nodePtr == NULL)
        {
            nodePtr = new AVLTreeNode(key, NULL, NULL);//first element added
        }
        // Else search for the insertion position

        else if (key < nodePtr->item)
        {
            insertItem(nodePtr->leftChildPtr, key);
        }
        else
        {
            insertItem(nodePtr->rightChildPtr, key);
        }

        updateBalanceFactor(nodePtr);//new balance factor
        int balance = nodePtr->balanceFactor;
        nodePtr->height = getNodeHeight(nodePtr);

        if(nodePtr->leftChildPtr != NULL && balance > 1)
        {
            //left
            if(key < nodePtr->leftChildPtr->item)
            {
                //LL
                singleRightRotation(nodePtr);
                nodePtr->height = getNodeHeight(nodePtr);
            }
            else if(key > nodePtr->leftChildPtr->item)
            {
                //LR
//                singleLeftRotation(nodePtr->leftChildPtr);
//                singleRightRotation(nodePtr);
                doubleLeftRight(nodePtr);
                nodePtr->height = getNodeHeight(nodePtr);
            }

        }

        if(nodePtr->rightChildPtr != NULL && balance < -1)
        {
            //right
            if(key < nodePtr->rightChildPtr->item)
            {
                //RL
//                singleRightRotation(nodePtr->rightChildPtr);
//                singleLeftRotation(nodePtr);
                doubleRightLeft(nodePtr);
                nodePtr->height = getNodeHeight(nodePtr);
            }
            else if(key > nodePtr->rightChildPtr->item)
            {
                //RR
                singleLeftRotation(nodePtr);
                nodePtr->height = getNodeHeight(nodePtr);
            }
        }
    }

    void inorder(AVLTreeNode* nodePtr)
    {
        if(nodePtr != NULL)
        {
            inorder(nodePtr->leftChildPtr);
            cout<<" "<<nodePtr->item<<" ";
            inorder(nodePtr->rightChildPtr);
        }
    }

    void preorder(AVLTreeNode* nodePtr)
    {
        if(nodePtr != NULL)
        {
            cout<<" "<<nodePtr->item<<" ";
            preorder(nodePtr->leftChildPtr);
            preorder(nodePtr->rightChildPtr);
        }
    }

    void postorder(AVLTreeNode* nodePtr)
    {
        if(nodePtr != NULL)
        {
            postorder(nodePtr->leftChildPtr);
            postorder(nodePtr->rightChildPtr);
            cout<<" "<<nodePtr->item<<" ";
        }
    }

    void deleteItem(AVLTreeNode*& nodePtr, int key)
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
                deleteItem(nodePtr->leftChildPtr, key);
            }
            else
            {
                deleteItem(nodePtr->rightChildPtr, key);
            }
            //after regular BST deletion perform these
            //first update height.
            if(nodePtr != NULL)
            {
                //nodePtr will be null after deletion if deleted node is a leaf
                nodePtr->height = getNodeHeight(nodePtr);
                updateBalanceFactor(nodePtr);//new balance factor
                int balance = nodePtr->balanceFactor;

                if(nodePtr->leftChildPtr != NULL && balance > 1)
                {
                    updateBalanceFactor(nodePtr->leftChildPtr);
                    if(nodePtr->leftChildPtr->balanceFactor >= 0)
                    {
                        //LL
                        singleRightRotation(nodePtr);
                        nodePtr->height = getNodeHeight(nodePtr);
                    }
                    else if(nodePtr->leftChildPtr->balanceFactor < 0)
                    {
                        //LR
                        doubleLeftRight(nodePtr);
                        nodePtr->height = getNodeHeight(nodePtr);
                    }
                }
                if(nodePtr->rightChildPtr != NULL && balance < -1)
                {
                    updateBalanceFactor(nodePtr->rightChildPtr);
                    if(nodePtr->rightChildPtr->balanceFactor <= 0)
                    {
                        //RR
                        singleLeftRotation(nodePtr);
                        nodePtr->height = getNodeHeight(nodePtr);
                    }
                    else
                    {
                        //RL
                        doubleRightLeft(nodePtr);
                        nodePtr->height = getNodeHeight(nodePtr);
                    }
                }
            }
        }
    }

    void deleteNode(AVLTreeNode*&nodePtr)
    {
        AVLTreeNode* deleteThis;
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

    void processLeftmost(AVLTreeNode*& nodePtr, int &replacementItem)
    {
        if (nodePtr->leftChildPtr == NULL)
        {
            replacementItem = nodePtr->item;
            AVLTreeNode *delPtr = nodePtr;
            nodePtr = nodePtr->rightChildPtr;
            delPtr->rightChildPtr = NULL;
            delete delPtr;
        }
        else
            processLeftmost(nodePtr->leftChildPtr, replacementItem);

    }
    void getNodeCountHelper(AVLTreeNode*nodePtr, int &countOfNodes)
    {
        if(nodePtr != NULL)
        {
            countOfNodes++;
            getNodeCountHelper(nodePtr->leftChildPtr, countOfNodes);
            getNodeCountHelper(nodePtr->rightChildPtr, countOfNodes);
        }
    }


    int getHeightHelper(AVLTreeNode*nodePtr)
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

    bool isLevelFull(int levelNo)
    {
        int nodesInLevel = 0;
        this->isLevelFull(rootPtr, levelNo, nodesInLevel);
        if(nodesInLevel == pow(2, levelNo-1))
            return true;
        else
            return false;
    }

    void isLevelFull(AVLTreeNode* nodePtr, int i, int &nodeNumber)
    {
        if(nodePtr != NULL)
        {
            if(i==1)
                nodeNumber++;
            else
            {
                this->isLevelFull(nodePtr->leftChildPtr, i-1, nodeNumber);
                this->isLevelFull(nodePtr->rightChildPtr, i-1, nodeNumber);
            }
        }
    }

    void swapSiblings(AVLTreeNode*&nodePtr)
    {
        if(nodePtr != NULL)
        {
            AVLTreeNode *temp = nodePtr->leftChildPtr;
            nodePtr->leftChildPtr = nodePtr->rightChildPtr;
            nodePtr->rightChildPtr = temp;
            if(nodePtr->rightChildPtr != NULL)
            {
                swapSiblings(nodePtr->rightChildPtr);
            }
            if(nodePtr->leftChildPtr != NULL)
            {
                swapSiblings(nodePtr->leftChildPtr);
            }
        }
    }

//AVL Functions
    void singleRightRotation(AVLTreeNode*& problemNode)
    {

        if(problemNode != NULL)
        {
            AVLTreeNode* k2 = problemNode;
            AVLTreeNode* k1 = problemNode->leftChildPtr;
            //cout<<"k2, k1: "<<k2->item<<", "<<k1->item<<endl;
            if(k1 != NULL)
            {
                k2->leftChildPtr = k1->rightChildPtr;
                k1->rightChildPtr = k2;
                problemNode = k1;

                //update height
                k1->height = getNodeHeight(k1);
                k2->height = getNodeHeight(k2);
            }

        }

    }

    void singleLeftRotation(AVLTreeNode*& problemNode)
    {
        if(problemNode != NULL)
        {
            AVLTreeNode* k2 = problemNode;
            AVLTreeNode* k1 = problemNode->rightChildPtr;
            if(k1 != NULL)
            {
                k2->rightChildPtr = k1->leftChildPtr;
                k1->leftChildPtr = k2;
                problemNode = k1;
                //updateNodeHeight(k1);
                //updateNodeHeight(k2);
            }
        }
    }

    void doubleRightLeft(AVLTreeNode*& problemNode)
    {
        //RL
        if(problemNode != NULL)
        {
            if(problemNode->rightChildPtr != NULL){
                singleRightRotation(problemNode->rightChildPtr);
                singleLeftRotation(problemNode);
            }
        }
    }

    void doubleLeftRight(AVLTreeNode*& problemNode)
    {
        //LR
        if(problemNode != NULL)
        {
            if(problemNode->leftChildPtr != NULL){
                singleLeftRotation(problemNode->leftChildPtr);
                singleRightRotation(problemNode);
            }
        }
    }

    int getNodeHeight(AVLTreeNode*ptr)
    {
        return getHeightHelper(ptr);
    }

    void updateBalanceFactor(AVLTreeNode*&ptr)
    {
        //left-high: 1
        //equal: 0
        //right-high: -1
        if(ptr != NULL)
        {
            int leftH = getNodeHeight(ptr->leftChildPtr);
            int rightH = getNodeHeight(ptr->rightChildPtr);
            ptr->balanceFactor = leftH - rightH; //-2 or 2 -> unbalanced
        }

    }

    void updateNodeHeight(AVLTreeNode*& nodePtr)
    {
        //eklediðin path in hegihtýný artýr.
        if(nodePtr != NULL)
            nodePtr->height +=  1;
    }


    void levelOrder(AVLTreeNode*ptr)
    {
        //call it with root
        int height = getNodeHeight(ptr);
        for(int i = 1; i<=height; i++)
        {
            printLevel(ptr, i);
            cout<<endl;
        }
    }

    void printLevel(AVLTreeNode* ptr, int level)
    {
        if(ptr != NULL)
        {
            if(level==1)
                cout<<ptr->item<<" ";
            else if(level>1)
            {
                printLevel(ptr->leftChildPtr, level-1);
                printLevel(ptr->rightChildPtr, level-1);
            }
        }
        else
            return;
    }



public:
//default constructor for binary search tree
    AVLTree();
//non-default constructors for binary search tree
    AVLTree( const int& rootItem);
//constructor that can take two trees for left and right-this is not a copy constructor
    AVLTree( const int& rootItem, const AVLTree &leftTreePtr, const AVLTree &rightTreePtr);
//copy constructor
    AVLTree( const AVLTree& tree);
//Destructor-No idea why this is virtual
    virtual ~AVLTree();
    bool isEmpty();
    void attachLeftSubtree(AVLTree &leftTree);
    void attachRightSubtree(AVLTree &rightTree);
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
