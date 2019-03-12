/*
* Title : Algorithm Efficiency and Sorting
* Author : Elif Gulsah Kasdogan
* ID : 21601183
* Section : 2
* Assignment : 1
* Description : Sorting Algorithms header file
*/
#include <iostream>
using namespace std;

void insertionSort(int *arr, int first, int last, int &compCount, int &moveCount);
void mergeFunction(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void swapFunc(int*arr, int firstPosition, int secondPosition);
void partitionFunc(int*arr,int first,int last,int &pivotIndex,int &compCount, int&moveCount);
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
void hybridSort(int *arr, int first, int last, int &compCount, int &moveCount);
void performanceAnalysis(int size);

int*createArray(int arraySize);
int* createAscending(int arraySize);
int* createDescending(int arraySize);
int* createIdentical(int arraySize, int*arrToCopy);
void printAll(int arr[], int arraySize);

