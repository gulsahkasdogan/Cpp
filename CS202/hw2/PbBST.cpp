/**
* Title : Binary Search Trees
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 2
* Description : CPP file for pointer based tree implementation
*/
#include <iostream>
using namespace std;
#include "PbBST.h"
#include "PbBSTNode.h"

    //default constructor for binary search tree
    PbBST::PbBST(){
        rootPtr = NULL;
    }

    //non-default constructors for binary search tree
    PbBST::PbBST( const int& rootItem){
        rootPtr = new PbBSTNode(rootItem);
    }

    //constructor that can take two trees for left and right-this is not a copy constructor
    PbBST::PbBST( const int& rootItem, const PbBST &leftTreePtr, const PbBST &rightTreePtr){
        rootPtr = new PbBSTNode(rootItem, leftTreePtr.rootPtr, rightTreePtr.rootPtr);
        //alternatively you can attach a tree.
        //It might be better to use attach in fact - CHECK AGAIN
    }

    //copy constructor
    PbBST::PbBST( const PbBST& tree){
        //we need a deep copy here
        //use auxiliary function
        copyTree(tree.rootPtr,rootPtr);
    }

    //Destructor
    PbBST::~PbBST(){
        //use auxiliary function
        destroy(rootPtr);
    }

    bool PbBST::isEmpty(){
        if(rootPtr == NULL)
            return true;
        else
            return false;
    }

//    void PbBST::attachLeftSubtree(PbBST &leftTree){}
//    void PbBST::attachRightSubtree(PbBST &rightTree){}

//              HW functions
    void PbBST::insertKey(int key){
        insertItem(rootPtr, key);
    }
    void PbBST::deleteKey(int key){
        deleteItem(rootPtr, key);
    }
    int PbBST::getHeight(){
        int maxHeight = getHeightHelper(rootPtr);
        return maxHeight;
    }
    int PbBST::getNodeCount(){
        int countOfNodes = 0;
        getNodeCountHelper(rootPtr, countOfNodes);
        return countOfNodes;
    }
    int PbBST::findNodesRequired(){
        int numberOfNodes = getNodeCount();
        int height = getHeight();
        int expectedNodes = 0;
        for(int i=0; i<height; i++){
            expectedNodes += pow(2,i);
        }
        return (expectedNodes-numberOfNodes);
    }

    int PbBST::findFullBTLevel(){
        int numOfLevels = getHeight();
        if(numOfLevels == 0)
            return 0;//empty
        else{
            for(int i=1; i<= numOfLevels; i++){
               if(!this->isLevelFull(i)){
                    return i-1;
               }
            }
        }
        return numOfLevels;
    }

    void PbBST::mirrorTree(){
        swapSiblings(rootPtr);
    }

    void PbBST::printTree(){
        if(this->getNodeCount()==0)
            cout<<"Tree is empty"<<endl;
        else{

        }

    }

    void PbBST::inorderTraversal(){
        inorder(rootPtr);
        cout<<endl;
    }

    void PbBST::preorderTraversal(){
        preorder(rootPtr);
        cout<<endl;
    }

    void PbBST::postorderTraversal(){
        postorder(rootPtr);
        cout<<endl;
    }
