//
// Created by Ian on 18/9/2024.
//

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>
#include <algorithm>

class SelectionSort {
public:
    void sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(arr[minIndex], arr[i]);
        }
    }
};

#endif

