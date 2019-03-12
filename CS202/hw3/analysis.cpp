/**
* Title : AVL tree analysis
* Author : Elif Gulsah Kasdogan
* ID: 21601183
* Section : 2
* Assignment : 3
* Description : analysis for height
*/

#include <iostream>
using namespace std;
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include "analysis.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

void heightAnalysis(){
    int increment = 4000;
    int*random = createRandom(80000);
    int*asc = createAscending(80000);
    int*desc = createDescending(80000);

    cout<<"Part b - Height analysis of AVL trees"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Array Size      Random       Ascending       Descending"<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    int size = 0;
    while(size < 80000){
        size += increment;
        anotherHelper(size, random, asc, desc);
        cout<<endl;
    }
}

int* createRandom(int size){
   int *arr = new int[size];
   for(int i = 0; i < size; i++){
        arr[i] = rand()%100 + 1;
   }
   return arr;
}

int* createAscending(int size){
    int* arr = new int[size];
    for(int i = 0; i<size; i++){
        arr[i] = i;
    }
    return arr;
}

int* createDescending(int size){
    int* arr = new int[size];
    for(int i=0; i<size; i++){
        arr[i] = size - i;
    }
    return arr;
}

void createTree(AVLTree &tree, int* arr, int size){
    //pass empty tree to this function
    for(int i = 0; i<size; i++){
        tree.insertKey(arr[i]);
    }
    //deletes array
    delete[]arr;
    arr = NULL;
}

void heightAnalysisHelper(int size){
    AVLTree randomTree;
    AVLTree ascTree;
    AVLTree descTree;

    int* randomArray = NULL;
    int* ascending = NULL;
    int* descending = NULL;

    //createRandom
    randomArray = createRandom(size);
    createTree(randomTree, randomArray, size);
    cout<<"Height "<<size<<" random: "<<randomTree.getHeight()<<endl;

    //createAscending
    ascending = createAscending(size);
    createTree(ascTree, ascending, size);
    cout<<"Height "<<size<<" ascending: "<<ascTree.getHeight()<<endl;

    //createDescending
    descending = createDescending(size);
    createTree(descTree, descending, size);
    cout<<"Height "<<size<<" descending: "<<descTree.getHeight()<<endl;
}

void anotherHelper(int size, int*random, int*asc, int*desc){
    AVLTree randomTree;
    AVLTree ascTree;
    AVLTree descTree;
    cout<<size<<"           ";
    for(int i = 0; i<size; i++){
        randomTree.insertKey(random[i]);
    }
    cout<<randomTree.getHeight()<<"             ";

    for(int i = 0; i<size; i++){
        ascTree.insertKey(asc[i]);
    }

    cout<<ascTree.getHeight()<<"                ";

    for(int i=0; i<size; i++){
        descTree.insertKey(desc[i]);
    }

    cout<<descTree.getHeight();

}



