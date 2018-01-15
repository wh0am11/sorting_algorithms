#ifndef __sorting_algorithms__
#define __sorting_algorithms__

#include "extra_functions.h"

void bubble_sort(int array[], int size) {

	int swaps = 1, i = 0;

	while (swaps > 0) {

		swaps = 0;

		for (i = 0; i < size - 1; i++) {

			if (array[i] > array[i + 1]) {

				int tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				++swaps;
			}
		}

	}

}

void insertion_sort(int array[], int size) {

	int i = 0;

	for (i = 0; i < size - 1; i++) {

		if (array[i] > array[i + 1]) {

			int val = array[i + 1], k = 0;
			array[i + 1] = array[i];
			array[i] = val;

			for (k = 0; k < (i + 1); k++) {

				if (array[k] > array[k + 1]) {

					int tmp = array[k + 1];
					array[k + 1] = array[k];
					array[k] = tmp;
				}
			}
		}
	}

}

void selection_sort(int array[], int size) {

	int i = 0;

	for (i = 0; i < size - 1; i++) {

		int index = find_lowest(array, size, i), val = array[i];
		array[i] = array[index];
		array[index] = val;
	}

}


int *merge_sort(int array[], int size) {

	if (size == 1) 
		return array;

	int size1 = 0, size2 = 0, *array1 = NULL, *array2 = NULL;

	if (size % 2 == 0) 
		size1 = size / 2, size2 = size / 2;
	else
		size1 = (size - 1) / 2, size2 = size - size1;

	
	array1 = calloc(size1, sizeof(int)), array2 = calloc(size2, sizeof(int));

	if (array1 && array2) {

		int *sorted = NULL;

		memcpy(array1, array, size1 * sizeof(int));
		memcpy(array2, array + size1, size2 * sizeof(int));

		memcpy(array1, merge_sort(array1, size1), size1 * sizeof(int));
		memcpy(array2, merge_sort(array2, size2), size2 * sizeof(int));

		sorted = msort(array1, array2, size1, size2);

		memcpy(array, sorted, size * sizeof(int));
		free(sorted);
		free(array1);
		free(array2);

	} else {

		if (array1) free(array1);
		if (array2) free(array2);
	}


	return array;

}


int *quicksort(int array[], int size) {

	if (size == 1)
		return array;

	int i = 0, j = 0, pivot_index = size - 1, pivot = array[pivot_index];

	for (i = 0; i < pivot_index; i++) {

		if (array[i] <= pivot) {


			int tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			++j;
		}
	}

	int tmp = array[pivot_index];
	array[pivot_index] = array[j];
	array[j] = tmp;
	pivot_index = j;



	int *sarray = NULL, *sarray2 = NULL, end_pivot = size - pivot_index;

	if (pivot_index > 0) 
		sarray = calloc(pivot_index, sizeof(int));
	if (end_pivot > 0)
		sarray2 = calloc(end_pivot, sizeof(int));

	if (sarray) {

		memcpy(sarray, quicksort(array, pivot_index), pivot_index * sizeof(int));
		memcpy(array, sarray, pivot_index * sizeof(int));
	}

	if (sarray2) {

		if (sarray) {

			memcpy(sarray2, quicksort(array + pivot_index, end_pivot), end_pivot * sizeof(int));
			memcpy(array + pivot_index, sarray2, end_pivot * sizeof(int));
		} else {

			memcpy(sarray2, quicksort(array, end_pivot), end_pivot * sizeof(int));
			memcpy(array, sarray2, end_pivot * sizeof(int));
		}
	}

		
	if (sarray) free(sarray);
	if (sarray2) free(sarray2);


	return array;

}

#endif
