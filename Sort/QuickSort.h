#pragma once
#include "Sort.h"
class QuickSort :
    public Sort
{
private:
    int comparisonsCount = 0;
    int swapCount = 0;
    long duration = 0;

    int hz(int* array, int left, int right) {
        int pivot = array[(right + left) / 2];
        while (left <= right) {
            comparisonsCount++;
            while (array[left] < pivot) { comparisonsCount++; left++; }
            while (array[right] > pivot) { comparisonsCount++; right--; }
            if (left <= right) {
                swapCount++;
                swap(array, left, right);
                left++;
                right--;
            }
        }
        return left;
    }
    void hz2(int* array, int start, int end) {
        comparisonsCount++;
        if (start >= end)
            return;
        int right = hz(array, start, end);
        hz2(array, start, right-1);
        hz2(array, right, end);
    }
public:
    void sort(int* array, int size) override {
        auto start = std::chrono::high_resolution_clock::now();
        comparisonsCount = 0;
        swapCount = 0;
        hz2(array, 0, size - 1);
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

