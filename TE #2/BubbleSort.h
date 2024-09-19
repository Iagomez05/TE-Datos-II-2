//
// Created by Ian on 18/9/2024.
//

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include <algorithm>

class BubbleSort {
public:
    void sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

#endif


