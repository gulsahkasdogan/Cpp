/**
* Title : AVL Tree main function
* Author : Elif Gülþah Kaþdoðan
* ID: 21601183
* Section : 2
* Assignment : 3
* Description : main menu hw3
*/
#include <iostream>
using namespace std;
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include "analysis.h"
const int MAX_SIZE = 11;

int main(){

    AVLTree tree;
    int arr[MAX_SIZE] = { 5, 10, 15 , 60 ,8 ,40 ,2 ,30 ,17, 12, 74};
    for(int i=0; i<MAX_SIZE; i++){
        tree.insertKey(arr[i]);
    }

    tree.printTree();

    tree.deleteKey(30);
    tree.deleteKey(10);
    tree.deleteKey(8);
    tree.deleteKey(74);
    tree.deleteKey(5);

    tree.printTree();

    heightAnalysis();

    return 0;
}
