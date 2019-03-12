#include <iostream>
using namespace std;
#include "PbBST.h"
#include "PbBSTNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include "analysis.h"

void shuffleArray(int *&arr, int size){
    for(int i = 0; i<size; i++){
        int randomIndex = rand()%size;
        int temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}
void timeAnalysis(){
    PbBST tree;
    int SIZE = 15000;
    int portion = 1500;
    int *arr = new int[SIZE];

    clock_t t0; //clock object
    clock_t t1;

    //create array with random integers size 15.000
    for(int i = 0; i<SIZE; i++){
        arr[i] = rand();
    }

    cout<<"Part e - Time analysis of Binary Search Tree - part 1"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Tree Size         Time Elapsed"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    //insert to tree size: 1.500
    float time = 0;
    for(int j = 0; j<10; j++){
        t0 = clock(); //mark this time

        for(int i = j*portion ; i< (j+1)*portion ; i++){
            tree.insertKey(arr[i]);
        }

        for(int i = 0; i<10000000; i++){
            //delay
        }

        t1 = clock();//end
        time += ((float)t1-t0) / (CLOCKS_PER_SEC*1000);
//        cout<<j*portion + portion<<"         ";
//        cout<<time<<endl;
        cout<<tree.getHeight()<<endl;
    }

    //shuffle
    shuffleArray(arr, SIZE);

    //delete from tree by choosing from shuffled array one by one
    cout<<"Part e - Time analysis of Binary Search Tree - part 2"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Tree Size         Time Elapsed"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    time = 0;
    for(int j = 0; j<10; j++){
        t0 = clock(); //mark this time

        for(int i = j*portion ; i< (j+1)*portion ; i++){
             tree.deleteKey(arr[i]);
        }

        for(int i = 0; i<10000000; i++){
            //delay
        }

        t1 = clock();//end
        time += ((float)t1-t0) / (CLOCKS_PER_SEC*1000);
        cout<<j*portion + portion<<"         ";
        cout<<time<<endl;
    }


    delete[]arr;

}




