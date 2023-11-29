#pragma once
#include "Sort.h"
class MergeSort :
    public Sort
{
private:
    int comparisonsCount = 0;
    int swapCount = 0;
    long duration = 0;
    int* mergeParts(int* arr1, int size1, int* arr2, int size2) {
        int* result = new int[size1 + size2];
        int id1 = 0;
        int id2 = 0;
        for (int i = 0; i < size1+size2; i++) {
            if (id1 < size1 - 1 && id2 < size2 - 1) {
                if (arr1[id1] < arr2[id2]) {
                    result[i] = arr1[id1++];
                }
                else {
                    result[i] = arr2[id2++];
                }
            }
            else {
                if (id1 < size1 - 1) {
                    result[i] = arr1[id1++];
                }
                else {
                    result[i] = arr2[id2++];
                }
            }
        }
        delete[] arr1;
        delete[] arr2;
        return result;
    }
    int* mergeSort(int* array, int size) {
        if (size == 1)
            return array;
        int midInd = size / 2;
        int* leftPart = new int[midInd];
        int* rightPart = new int[size - midInd];

        for (int i = 0; i < midInd; i++) {
            leftPart[i] = array[i];
        }

        for (int i = midInd; i < size - midInd; i++) {
            rightPart[i-midInd] = array[i];
        }
        delete[] array;
        if (size == 2)
            return mergeParts(leftPart, midInd, rightPart, size-midInd);
        return mergeParts(mergeSort(leftPart, midInd), midInd, mergeSort(rightPart, size - midInd), size - midInd);
    }
public:
    void sort(int* array, int size) override {
        auto start = std::chrono::high_resolution_clock::now();
        array = mergeSort(array, size);
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

