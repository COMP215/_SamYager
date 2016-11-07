/* 
Sam Yager
Sorting.cpp
	Implements three sorting algorithms in ascending order
	The Bubble Sort
	The Selection Sort
	The Merge Sort
*/

#include <iostream>
#include <iomanip>
using namespace std;
void Merge(int *, int, int, int);

void PrintArray(int* array, int size) {
	for (int i=0; i< size; i++) {
		cout << array[i] << " ";
	} cout << endl;
}

void BubbleSort(int* myarray, int array_size) {
	bool isdone = false;	//stays false if a swap occurs

	cout << "Initial Array: ";
	PrintArray(myarray, array_size);	//print initial array

	while (isdone == false) {
		isdone = true;
		for (int i=0; i<(array_size-1); i++) {
			if (myarray[i+1] < myarray[i]) {
				swap(myarray[i], myarray[i+1]);
				isdone = false;
			}
		}
	}
	cout << "Bubble Sorted: ";
	PrintArray(myarray, array_size);	//print sorted array
}

void SelectionSort(int* array, int array_size) {
	int min_index;
	for (int i=0; i < array_size; i++) {
		min_index = i;
		for (int j=i; j < array_size; j++) {
			if (array[min_index] > array[j]) {
				min_index = j;
			}
		}
		swap(array[i], array[min_index]);
	}

	cout << "Selection Sort: ";
	PrintArray(array, array_size);
}

void MergeSort(int *array, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		MergeSort(array, low, mid);
		MergeSort(array, mid+1, high);
		Merge(array, low, mid, high);
	}
}

void Merge(int *array, int low, int middle, int high) {
	int lowcounter, midcounter, numchanges, temparray[50];
	lowcounter = low;
	numchanges = low;
	midcounter = middle + 1;

	while ((lowcounter <= middle) && (midcounter <= high)) {
		if (array[lowcounter] <= array[midcounter]) {
			temparray[numchanges] = array[lowcounter];
			numchanges++;
			lowcounter++;
		} else {
			temparray[numchanges] = array[midcounter];
			numchanges++;
			midcounter++;
		}
	}
	while (lowcounter <= middle) {
		temparray[numchanges] = array[lowcounter];
		numchanges++;
		lowcounter++;
	}
	while (midcounter <= high) {
		temparray[numchanges] = array[midcounter];
		numchanges++;
		midcounter++;
	}
	for (lowcounter = low; lowcounter < numchanges; lowcounter++) {
		array[lowcounter] = temparray[lowcounter];
	}
}
 
int main () {
	int array1[] = {70,2,5,7,10,19,6,1,72,8};
	BubbleSort(array1, 10);

	int array2[] = {70,2,5,7,10,19,6,1,72,8};
	SelectionSort(array2, 10);

	int array3[] = {70,2,5,7,10,19,6,1,72,8};
	MergeSort(array3, 0, 10);
	cout << "Merge Sorted:  ";
	PrintArray(array3, 10);
	return 0;
}