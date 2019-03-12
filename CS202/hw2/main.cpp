/**
* Title : Binary Search Trees
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 2
* Description : Main function for pointer based tree tester
*/
#include <iostream>
using namespace std;
#include "PbBST.h"
#include "PbBSTNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include "analysis.h"
int MAX_SIZE = 16;
int main(){
    PbBST tree;
    int arr[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 14, 5};
    for(int i=0; i<MAX_SIZE; i++){
        tree.insertKey(arr[i]);
    }

    cout<<"Number of Required Nodes: "<<tree.findNodesRequired()<<endl;

    tree.deleteKey(7);
    tree.deleteKey(8);

    cout<<"Full BT Level: "<<tree.findFullBTLevel()<<endl;

    //create a mirrored copy
    PbBST original = tree; // original tree-copy constructor used

    tree.mirrorTree();//this is the mirrored one
    cout<<"Inorder of original"<<endl;
    original.inorderTraversal();

    cout<<"Inorder of mirrored"<<endl;
    tree.inorderTraversal();

   //timeAnalysis();

    return 0;
}
