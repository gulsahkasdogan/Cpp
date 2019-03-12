/**
* Title : AVL tree
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 3
* Description : CPP file for AVL implementation
*/
#include <iostream>
using namespace std;
#include "AVLTree.h"
#include "AVLTreeNode.h"

    //default constructor for binary search tree
    AVLTree::AVLTree(){
        rootPtr = NULL;
        shorter = true;
    }

    //non-default constructors for binary search tree
    AVLTree::AVLTree( const int& rootItem){
        rootPtr = new AVLTreeNode(rootItem);
        shorter = true;
    }

    //constructor that can take two trees for left and right-this is not a copy constructor
    AVLTree::AVLTree( const int& rootItem, const AVLTree &leftTreePtr, const AVLTree &rightTreePtr){
        rootPtr = new AVLTreeNode(rootItem, leftTreePtr.rootPtr, rightTreePtr.rootPtr);
        //alternatively you can attach a tree.
        //It might be better to use attach in fact - CHECK AGAIN
        shorter = true;
    }

    //copy constructor
    AVLTree::AVLTree( const AVLTree& tree){
        //we need a deep copy here
        //use auxiliary function
        copyTree(tree.rootPtr,rootPtr);
        shorter = tree.shorter;//?
    }

    //Destructor
    AVLTree::~AVLTree(){
        //use auxiliary function
        destroy(rootPtr);
    }

    bool AVLTree::isEmpty(){
        if(rootPtr == NULL)
            return true;
        else
            return false;
    }

//    void AVLTree::attachLeftSubtree(AVLTree &leftTree){}
//    void AVLTree::attachRightSubtree(AVLTree &rightTree){}

    void AVLTree::insertKey(int key){
        insertItem(rootPtr, key);
    }

    void AVLTree::deleteKey(int key){
       deleteItem(rootPtr, key);
    }

    int AVLTree::getHeight(){
        int maxHeight = getHeightHelper(rootPtr);
        return maxHeight;
    }
    int AVLTree::getNodeCount(){
        int countOfNodes = 0;
        getNodeCountHelper(rootPtr, countOfNodes);
        return countOfNodes;
    }
    int AVLTree::findNodesRequired(){
        int numberOfNodes = getNodeCount();
        int height = getHeight();
        int expectedNodes = 0;
        for(int i=0; i<height; i++){
            expectedNodes += pow(2,i);
        }
        return (expectedNodes-numberOfNodes);
    }

    int AVLTree::findFullBTLevel(){
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

    void AVLTree::mirrorTree(){
        swapSiblings(rootPtr);
    }

    void AVLTree::printTree(){
        if(this->getNodeCount()==0)
            cout<<"Tree is empty"<<endl;
        else{

            levelOrder(rootPtr);
            //constructArray(rootPtr);
        }
    }

    void AVLTree::inorderTraversal(){
        inorder(rootPtr);
        cout<<endl;
    }

    void AVLTree::preorderTraversal(){
        preorder(rootPtr);
        cout<<endl;
    }

    void AVLTree::postorderTraversal(){
        postorder(rootPtr);
        cout<<endl;
    }

