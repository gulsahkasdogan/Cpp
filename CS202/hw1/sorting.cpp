/*
* Title : Algorithm Efficiency and Sorting
* Author : Elif Gulsah Kasdogan
* ID : 21601183
* Section : 2
* Assignment : 1
* Description : Sorting Algorithms
*/
#include <iostream>
#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>

#include <ctime>
using namespace std;

const int MIN_SIZE=10;

void insertionSort(int *arr, int first, int last, int &compCount, int &moveCount)
{

    for(int i=1; i <= last ; i++)
    {
        int nextItem = arr[i];
        moveCount++;

        int loc = i;
        for(; (loc>0)&&(arr[loc-1])>nextItem; loc--){
            compCount++;
            arr[loc]=arr[loc-1];
            moveCount++;
        }
        compCount++;

        arr[loc] = nextItem;
        moveCount++;

    }
}

void mergeFunction(int *arr, int first, int mid, int last, int &compCount, int &moveCount)
{
    int temp[first+last+1];
    int first1 = first;
    int first2 = mid+1;
    int last1 = mid;
    int last2 = last;
    int index = first1;

    while((first1<=last1) && (first2<=last2))
    {
        if(arr[first1]<arr[first2])
        {
            temp[index] = arr[first1];
            moveCount++;
            first1++;
        }
        else
        {
            temp[index] = arr[first2];
            moveCount++;
            first2++;
        }
        index++;
        compCount++;
    }
    //one of the two sublists might not be done at this point
    //take list1 if not ended
    while(first1<=last1)
    {
        temp[index]=arr[first1];
        moveCount++;
        first1++;
        index++;
    }

    //take list2 if not ended
    while(first2<=last2)
    {
        temp[index]=arr[first2];
        moveCount++;
        first2++;
        index++;
    }

    //copy everything back
    for(int i = first; i<=last; i++)
    {
        arr[i]=temp[i];
        moveCount++;
    }
}//end of merge function

void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    if(first<last)
    {
        int mid = (first+last)/2;
        mergeSort(arr,first,mid,compCount,moveCount);//first half
        mergeSort(arr,mid+1,last,compCount,moveCount);//second half
        mergeFunction(arr,first,mid,last,compCount,moveCount);//merge
    }
}


void swap(int &first, int&second)
{
    int temp = first;
    first = second;
    second = temp;
}

void partition(int*arr,int first,int last,int &pivotIndex,int &compCount, int&moveCount)
{
    //take pivot
    swap(arr[last],arr[first]);
    moveCount = moveCount+3;

    //now pivot is at the first position
    int pivot = arr[first];
    moveCount++;

    int lastS1 = first;
    int firstUnknown= first+1;

    for(;firstUnknown<=last ;firstUnknown++)
    {
        if(arr[firstUnknown]<pivot)
        {
            lastS1++;
            swap(arr[lastS1],arr[firstUnknown]);
            moveCount = moveCount+3;
        }

        compCount++;
    }

    swap(arr[lastS1],arr[first]);//arr[first]==pivot
    moveCount = moveCount+3;

    pivotIndex = lastS1;
}

void quickSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    int pivotIndex;

    if(first<last)
    {
        partition(arr,first,last,pivotIndex,compCount,moveCount);
        quickSort(arr,first,pivotIndex-1,compCount,moveCount);
        quickSort(arr,pivotIndex+1,last,compCount,moveCount);
    }
}

void hybridSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    if(last-first+1 >= MIN_SIZE)
    {
        //more then 10 elements
        int pivotIndex=0;
        partition(arr,first,last,pivotIndex,compCount,moveCount);
        quickSort(arr,first,pivotIndex-1,compCount,moveCount);
        quickSort(arr,pivotIndex,last,compCount,moveCount);
    }
    else
    {
        //less than 10 elements
        insertionSort(arr,first,last,compCount,moveCount);
    }
}

int* createArray(int arraySize)
{
    int* arr = new int[arraySize];
    for(int i=0; i<arraySize; i++)
    {
        arr[i]=(rand()%100) + 40;
    }
    return arr;
}

int* createAscending(int arraySize){
    int* arr = new int[arraySize];

    for(int i=0; i<arraySize; i++){
        arr[i]=i+1;
    }
    return arr;
}

int* createDescending(int arraySize){
    int* arr = new int[arraySize];
    int element=1;
    for(int i=arraySize-1; i>=0; i--){
        arr[i]=element;
        element++;
    }
    return arr;
}

int* createIdentical(int arraySize, int*arrToCopy){
    int* newArray = new int[arraySize];
    for(int i=0; i<arraySize; i++){
        newArray[i]=arrToCopy[i];
    }
    return newArray;
}

void printAll(int* arr, int arraySize)
{
    cout<<"[";
    for(int i = 0 ; i<arraySize; i++)
    {
        cout<<" " << arr[i]<<" ";
    }
    cout<<"]"<<endl;
}

void performanceAnalysis(int size)
{
    int moveCount = 0;
    int compCount = 0;


    //UNCOMMENT THIS PART FOR RANDOM INTEGERS
    int *ar1 = createArray(size);
    int *ar2 = createIdentical(size,ar1);
    int *ar3 = createIdentical(size,ar1);
    int *ar4 = createIdentical(size,ar1);

//    //UNCOMMENT THIS PART FOR ASCENDING ORDER
//    int *ar1 = createAscending(size);
//    int *ar2 = createAscending(size);
//    int *ar3 = createAscending(size);
//    int *ar4 = createAscending(size);

//    //UNCOMMENT THIS PART FOR DESCENDING ORDER
//    int *ar1 = createDescending(size);
//    int *ar2 = createDescending(size);
//    int *ar3 = createDescending(size);
//    int *ar4 = createDescending(size);

    clock_t t; //clock object
    t = clock();

    cout<<"INSERTION SORT"<<endl;
    insertionSort(ar1,0,(size-1),compCount,moveCount);
    cout<<"Comparison count: "<<compCount<<endl;
    cout<<"Movement count: "<<moveCount<<endl;

    t = clock() - t;
    cout<<"It took "<<((float)t)/((CLOCKS_PER_SEC)*1000)<<" miliseconds"<<endl<<endl;


    cout<<"MERGE SORT"<<endl;
    moveCount = 0;
    compCount = 0;
    t = clock();

    mergeSort(ar2,0,size-1,compCount,moveCount);
    cout<<"Comparison count: "<<compCount<<endl;
    cout<<"Movement count: "<<moveCount<<endl;


    t = clock() - t;
    cout<<"It took "<<((float)t)/((CLOCKS_PER_SEC)*1000)<<"miliseconds"<<endl<<endl;



    cout<<"QUICK SORT"<<endl;
    moveCount = 0;
    compCount = 0;
    t = clock();

    quickSort(ar3,0,size-1,compCount,moveCount);
    cout<<"Comparison count: "<<compCount<<endl;
    cout<<"Movement count: "<<moveCount<<endl;

    t = clock() - t;
    cout<<"It took "<<((float)t)/((CLOCKS_PER_SEC)*1000)<<"miliseconds"<<endl<<endl;


    cout<<"HYBRID SORT"<<endl;
    moveCount = 0;
    compCount = 0;
    t = clock();

    hybridSort(ar4,0,size-1,compCount,moveCount);
    cout<<"Comparison count: "<<compCount<<endl;
    cout<<"Movement count: "<<moveCount<<endl;

    t = clock() - t;
    cout<<"It took "<<((float)t)/((CLOCKS_PER_SEC)*1000)<<"miliseconds"<<endl<<endl;


    if(ar1)
        delete[]ar1;
    if(ar2)
        delete[]ar2;
    if(ar3)
        delete[]ar3;
    if(ar4)
        delete[]ar4;

}
