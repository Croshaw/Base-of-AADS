#pragma once
#include "Sort.h"
class BubbleSort :
    public Sort
{
private:
    int comparisonsCount = 0;
    int swapCount = 0;
    long duration = 0;
public:
    void sort(int* array, int size) override {
        auto start = std::chrono::high_resolution_clock::now();
        comparisonsCount = 0;
        swapCount = 0;
        int len = size;
        while(len != 0) {
            int max_index = 0;
            for (int j = 0; j < size-1; j++) {
                comparisonsCount++;
                if (array[j] > array[j + 1]) {
                    swap(array, j, j + 1);
                    swapCount++;
                    max_index = j;
                }
            }
            len = max_index;
        }
        duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();
    }
    int getComparisonsCount() override {
        return comparisonsCount;
    }
    int getSwapCount() override {
        return swapCount;
    }
    long getDuration() override {
        return duration;
    }
};

