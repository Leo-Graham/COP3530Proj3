//
// Created by leojg on 7/29/2024.
//

#ifndef PROJECT3_MERGESORT_H
#define PROJECT3_MERGESORT_H

#endif //PROJECT3_MERGESORT_H


#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <stack>
using namespace std;
using tupInfo = tuple<string,string,string,string,string,string,string,string,string,string,string,string,
        string,string,string,string,string,string,string,string,string,string,string,string>;

// Adapted from geeks-for-geeks heapsort implementation: https://www.geeksforgeeks.org/heap-sort/

//Heapify method
void heapify(int i, vector<tupInfo> &dataInfo, int choice, int sizeHeap)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    //Manages operation for user's choice of parameter
    if(choice == 9) {
        // Compares nodes
        if (l < sizeHeap && get<9>(dataInfo[l]) > get<9>(dataInfo[largest]))
            largest = l;
        if (r < sizeHeap && get<9>(dataInfo[r]) > get<9>(dataInfo[largest]))
            largest = r;
        // Swaps if needed
        if (largest != i) {
            swap(dataInfo[i], dataInfo[largest]);
            //Recurs until fully heapified.
            heapify(largest, dataInfo, choice, sizeHeap);
        }
    //Does similar process, but for parameters specified in a different user choice.
    }else if(choice == 10) {

        if (l < sizeHeap && get<10>(dataInfo[l]) > get<10>(dataInfo[largest]))
            largest = l;

        if (r < sizeHeap && get<10>(dataInfo[r]) > get<10>(dataInfo[largest]))
            largest = r;

        if (largest != i) {
            swap(dataInfo[i], dataInfo[largest]);

            heapify(largest, dataInfo, choice, sizeHeap);
        }

    }else if(choice == 14) {

        if (l < sizeHeap && get<14>(dataInfo[l]) > get<14>(dataInfo[largest]))
            largest = l;

        if (r < sizeHeap && get<14>(dataInfo[r]) > get<14>(dataInfo[largest]))
            largest = r;

        if (largest != i) {
            swap(dataInfo[i], dataInfo[largest]);

            heapify(largest, dataInfo, choice, sizeHeap);
        }

    }else if(choice == 15) {

        if (l < sizeHeap && get<15>(dataInfo[l]) > get<15>(dataInfo[largest]))
            largest = l;

        if (r < sizeHeap && get<15>(dataInfo[r]) > get<15>(dataInfo[largest]))
            largest = r;

        if (largest != i) {
            swap(dataInfo[i], dataInfo[largest]);

            heapify(largest, dataInfo, choice, sizeHeap);
        }

    }else if(choice == 16) {

        if (l < sizeHeap && get<16>(dataInfo[l]) > get<16>(dataInfo[largest]))
            largest = l;

        if (r < sizeHeap && get<16>(dataInfo[r]) > get<16>(dataInfo[largest]))
            largest = r;

        if (largest != i) {
            swap(dataInfo[i], dataInfo[largest]);

            heapify(largest, dataInfo, choice, sizeHeap);
        }

    }else if(choice == 17) {

        if (l < sizeHeap && get<17>(dataInfo[l]) > get<17>(dataInfo[largest]))
            largest = l;

        if (r < sizeHeap && get<17>(dataInfo[r]) > get<17>(dataInfo[largest]))
            largest = r;

        if (largest != i) {
            swap(dataInfo[i], dataInfo[largest]);

            heapify(largest, dataInfo, choice, sizeHeap);
        }

    }
}


//Heap sorting method
void heapSort(vector<tupInfo> &dataInfo, int choice)
{
    //Builds heap
    for (int i = dataInfo.size() / 2 - 1; i >= 0; i--)
        heapify(i, dataInfo, choice, dataInfo.size());
    //Extracts elements from heap for output
    for (int i = dataInfo.size() - 1; i >= 0; i--) {

        swap(dataInfo[0], dataInfo[i]);
        //Heapifies the reduced heap
        heapify(0, dataInfo, choice, i);
    }
}
