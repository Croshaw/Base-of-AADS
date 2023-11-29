#pragma once
#include "Sort.h"
class ShellSort :
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
        int h = size/2;
        while (h > 0) {
            for (int i = h; i < size; i++) {
                comparisonsCount++;
                while (i >= h && array[i - h] > array[i]) {
                    swap(array, i - h, i);
                    i -= h;
                    swapCount++;
                    comparisonsCount++;
                }
            }
            h /= 2;
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

