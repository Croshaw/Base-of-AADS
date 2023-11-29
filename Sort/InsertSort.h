#pragma once
#include "Sort.h"
class InsertSort :
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
        for (int i = 1; i < size; i++) {
            int curIndex = i;
            for (int j = i - 1; j >= 0; j--) {
                comparisonsCount++;
                if (array[curIndex] < array[j]) {
                    swap(array, curIndex, j);
                    swapCount++;
                    curIndex = j;
                }
                else
                    break;
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

