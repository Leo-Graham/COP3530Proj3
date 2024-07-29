//
// Created by leojg on 7/29/2024.
//

#ifndef PROJECT3_MERGESORT_H
#define PROJECT3_MERGESORT_H

#endif //PROJECT3_MERGESORT_H


// C++ program for implementation of Heap Sort
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <stack>
using namespace std;
using tupInfo = tuple<string,string,string,string,string,string,string,string,string,string,string,string,
        string,string,string,string,string,string,string,string,string,string,string,string>;

// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
void heapify(int i, vector<tupInfo> &dataInfo, int choice)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if(choice == 1) {

            // If left child is larger than root
            if (l < dataInfo.size() && get<9>(dataInfo[l]) > get<9>(dataInfo[largest]))
                largest = l;

            // If right child is larger than largest so far
            if (r < dataInfo.size() && get<9>(dataInfo[l]) > get<9>(dataInfo[largest]))
                largest = r;

            // If largest is not root
            if (largest != i) {
                swap(get<9>(dataInfo[l]), get<9>(dataInfo[largest]));

                // Recursively heapify the affected subtree
                heapify(largest, dataInfo, choice);
            }

    }
    if(choice == 2) {
            // If left child is larger than root
            if (l < dataInfo.size() && get<10>(dataInfo[l]) > get<10>(dataInfo[largest]))
                largest = l;

            // If right child is larger than largest so far
            if (r < dataInfo.size() && get<10>(dataInfo[l]) > get<10>(dataInfo[largest]))
                largest = r;

            // If largest is not root
            if (largest != i) {
                swap(get<10>(dataInfo[l]), get<10>(dataInfo[largest]));

                // Recursively heapify the affected subtree
                heapify(largest, dataInfo, choice);
            }

    }



}

// main function to do heap sort
void heapSort(vector<tupInfo> &dataInfo, int choice)
{
    // Build heap (rearrange array)
    for (int i = dataInfo.size() / 2 - 1; i >= 0; i--)
        heapify(i, dataInfo, choice);
    // One by one extract an element from heap
    for (int i = dataInfo.size() - 1; i >= 0; i--) {
        // Move current root to end
        swap(dataInfo[0], dataInfo[i]);
        // call max heapify on the reduced heap
        heapify(0, dataInfo, choice);
    }
}


//int main() {
//    tupInfo song3 = make_tuple("aoop","cde","cde","cde","cde","cde","cde","cde","cde","cde","cde",
//                               "cde","cde","cde","cde","cde","cde","cde","cde","cde","cde","cde","cde","cde");
//    tupInfo song1 = make_tuple("pee","abc","abc","abc","abc","abc","abc","abc","abc","abc","abc",
//                               "abc","abc","abc","abc","abc","abc","abc","abc","abc","abc","abc","abc","abc");
//    tupInfo song2 = make_tuple("fart","bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd",
//                               "bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd","bcd");
//
//    vector<tupInfo> bofa;
//    bofa.push_back(song1);
//    bofa.push_back(song2);
//    bofa.push_back(song3);
//
//    heapSort(bofa, 8);
//
//    for (int i = 0; i < 3;i++){
//        cout << get<0>(bofa[i]) << endl;
//    }
//
//    return 0;
//}
