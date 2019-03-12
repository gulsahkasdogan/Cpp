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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

void heightAnalysis();
int* createRandom(int size);
int* createAscending(int size);
int* createDescending(int size);
void createTree(AVLTree &tree, int* arr, int size);
void heightAnalysisHelper(int size);
void anotherHelper(int size,int*r, int*a, int*d);


