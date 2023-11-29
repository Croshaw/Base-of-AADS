#pragma once
#include "Sort.h"
class SelectionSort :
    public Sort
{
private:
    int comparisonsCount = 0;
    int swapCount = 0;
    long duration = 0;
public:
    void sort(int* array, int size) override {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < size; i++) {
            int min_index = i;
            for (int j = i+1; j < size; j++) {
                comparisonsCount++;
                if (array[j] < array[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                swap(array, min_index, i);
                swapCount++;
            }
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

