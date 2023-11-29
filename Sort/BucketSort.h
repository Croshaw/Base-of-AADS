#pragma once
#include "Sort.h"
#include <vector>
#include <list>
class BucketSort :
    public Sort
{
private:
    int comparisonsCount = 0;
    int swapCount = 0;
    long duration = 0;
    void getMaxMin(int* array, int size, int& min, int& max) {
        min = array[0];
        max = array[0];
        for (int i = 1; i < size; i++) {
            if (array[i] > max)
                max = array[i];
            if (array[i] < min)
                min = array[i];
        }
    }
public:
    void sort(int* array, int size) override {
        auto start = std::chrono::high_resolution_clock::now();

        std::vector<std::list<int>*> aux(size);
        int min = 0;
        int max = 0;

        for (int i = 0; i < size; i++)
            aux[i] = new std::list<int>();

        getMaxMin(array, size, min, max);
        int numRange = max - min;

        for (int i = 0; i < size; i++) {
            int id = floor((array[i]-min) / (numRange / aux.size()));
            if (id == aux.size()) id--;
            if (aux[id]->size() > 0) {
                if (array[i] < *aux[id]->begin()) {
                    aux[id]->push_front(array[i]);
                }
                else {
                    int curId = 0;
                    for (auto val : *aux[id]) {
                        if (val > array[i]) {
                            //aux[id]->insert(val, array[i]);
                            break;
                        }
                        curId++;
                    }
                }
            }
            aux[id]->push_back(array[i]);
        }
        int id = 0;
        for (int i = 0; i < size; i++) {
            for (int val : *aux[i]) {
                array[id++] = val;
            }
        }
        for (int i = 0; i < size; ++i) {
            delete aux[i];
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

