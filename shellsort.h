//
// Created by Speci on 7/29/2024.
//

#ifndef PROJECT3_SHELLSORT_H
#define PROJECT3_SHELLSORT_H

#endif //PROJECT3_SHELLSORT_H

//
// Created by Speci on 7/29/2024.
//
#pragma once
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using tupInfo = tuple<string,string,string,string,string,string,string,string,string,string,string,string,
        string,string,string,string,string,string,string,string,string,string,string,string>;

// Based on pseudo-code from TA notes
void ShellSorting(vector<tupInfo> &dataInfo, int choice){
    // first, figure out which choice we are sorting by
    // 9 = dance-ability
    if(choice == 9) {
        // start with a loop that's has a 1/2 gap, slowly closing the gap each time
        for (size_t i = dataInfo.size() / 2; i > 0; i /= 2) {
            for (int j = i; j < dataInfo.size(); j += 1) {
                tupInfo temp = dataInfo[j];

                int k;
                for (k = j; k >= i && get<9>(dataInfo[k - i]) > get<9>(temp); k -= i) {
                    dataInfo[k] = dataInfo[k - i];
                }
                dataInfo[k] = temp;
            }
        }
    }else if(choice == 10){
        // start with a loop that's has a 1/2 gap, slowly closing the gap each time
        for (size_t i = dataInfo.size() / 2; i > 0; i /= 2) {
            for (int j = i; j < dataInfo.size(); j += 1) {
                tupInfo temp = dataInfo[j];

                int k;
                for (k = j; k >= i && get<10>(dataInfo[k - i]) > get<10>(temp); k -= i) {
                    dataInfo[k] = dataInfo[k - i];
                }
                dataInfo[k] = temp;
            }
        }
    }else if(choice == 14){
        // start with a loop that's has a 1/2 gap, slowly closing the gap each time
        for (size_t i = dataInfo.size() / 2; i > 0; i /= 2) {
            for (int j = i; j < dataInfo.size(); j += 1) {
                tupInfo temp = dataInfo[j];

                int k;
                for (k = j; k >= i && get<14>(dataInfo[k - i]) > get<14>(temp); k -= i) {
                    dataInfo[k] = dataInfo[k - i];
                }
                dataInfo[k] = temp;
            }
        }
    }else if(choice == 15){
        // start with a loop that's has a 1/2 gap, slowly closing the gap each time
        for (size_t i = dataInfo.size() / 2; i > 0; i /= 2) {
            for (int j = i; j < dataInfo.size(); j += 1) {
                tupInfo temp = dataInfo[j];

                int k;
                for (k = j; k >= i && get<15>(dataInfo[k - i]) > get<15>(temp); k -= i) {
                    dataInfo[k] = dataInfo[k - i];
                }
                dataInfo[k] = temp;
            }
        }
    }else if(choice == 16){
        // start with a loop that's has a 1/2 gap, slowly closing the gap each time
        for (size_t i = dataInfo.size() / 2; i > 0; i /= 2) {
            for (int j = i; j < dataInfo.size(); j += 1) {
                tupInfo temp = dataInfo[j];

                int k;
                for (k = j; k >= i && get<16>(dataInfo[k - i]) > get<16>(temp); k -= i) {
                    dataInfo[k] = dataInfo[k - i];
                }
                dataInfo[k] = temp;
            }
        }
    }else if(choice == 17){
        // start with a loop that's has a 1/2 gap, slowly closing the gap each time
        for (size_t i = dataInfo.size() / 2; i > 0; i /= 2) {
            for (int j = i; j < dataInfo.size(); j += 1) {
                tupInfo temp = dataInfo[j];

                int k;
                for (k = j; k >= i && get<17>(dataInfo[k - i]) > get<17>(temp); k -= i) {
                    dataInfo[k] = dataInfo[k - i];
                }
                dataInfo[k] = temp;
            }
        }
    }
}