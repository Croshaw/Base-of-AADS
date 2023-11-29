#include <iostream>
#include "ArrayHelper.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "BucketSort.h"

void printArray(int* array, int size, std::string str = "") {
	if (str != "")
		std::cout << str;
	std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << (i == size - 1 ? "" : ", ");
	}
	std::cout << std::endl;
}

int main()
{
	ArrayHelper aHelper(10);
	printArray(aHelper.get(), aHelper.size(), "Original Array: ");


	BubbleSort bSort;
	int* a = aHelper.getCopyArray();
	bSort.sort(a, aHelper.size());
	std::cout << "Bubble Sort: Comparisons = " << bSort.getComparisonsCount() << " Swap Count = " << bSort.getSwapCount() << " Duration = " << bSort.getDuration() << " ms" << std::endl;
	//printArray(a, aHelper.size(), "Bubble Sort: ");


	SelectionSort selSort;
	int* b = aHelper.getCopyArray();
	selSort.sort(b, aHelper.size());
	std::cout << "Selection Sort: Comparisons = " << selSort.getComparisonsCount() << " Swap Count = " << selSort.getSwapCount() << " Duration = " << selSort.getDuration() << " ms" << std::endl;
	//printArray(b, aHelper.size(), "Selection Sort: ");



	InsertSort insSort;
	int* c = aHelper.getCopyArray();
	insSort.sort(c, aHelper.size());
	std::cout << "Insert Sort: Comparisons = " << insSort.getComparisonsCount() << " Swap Count = " << insSort.getSwapCount() << " Duration = " << insSort.getDuration() << " ms" << std::endl;
	//printArray(c, aHelper.size(), "Insert Sort: ");



	QuickSort quickSort;
	int* d = aHelper.getCopyArray();
	quickSort.sort(d, aHelper.size());
	std::cout << "Quick Sort: Comparisons = " << quickSort.getComparisonsCount() << " Swap Count = " << quickSort.getSwapCount() << " Duration = " << quickSort.getDuration() << " ms" << std::endl;
	printArray(d, aHelper.size(), "Quick Sort: ");



	/*MergeSort mergeSort;
	int* e = aHelper.getCopyArray();
	mergeSort.sort(e, aHelper.size());
	std::cout << "Merge Sort: Comparisons = " << mergeSort.getComparisonsCount() << " Swap Count = " << mergeSort.getSwapCount() << " Duration = " << mergeSort.getDuration() << " ms" << std::endl;
	printArray(e, aHelper.size(), "Merge Sort: ");*/


	ShellSort shellSort;
	int* f = aHelper.getCopyArray();
	shellSort.sort(f, aHelper.size());
	std::cout << "Shell Sort: Comparisons = " << shellSort.getComparisonsCount() << " Swap Count = " << shellSort.getSwapCount() << " Duration = " << shellSort.getDuration() << " ms" << std::endl;
	//printArray(f, aHelper.size(), "Shell Sort: ");


	BucketSort bucketSort;
	int* g = aHelper.getCopyArray();
	bucketSort.sort(g, aHelper.size());
	//std::cout << "Bucket Sort: Comparisons = " << bucketSort.getComparisonsCount() << " Swap Count = " << bucketSort.getSwapCount() << " Duration = " << bucketSort.getDuration() << " ms" << std::endl;
	printArray(g, aHelper.size(), "Bucket Sort: ");


	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	//delete[] e;
	delete[] f;
}