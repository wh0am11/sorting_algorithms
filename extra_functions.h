#ifndef __extra_functions__
#define __extra_functions__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*sorting_func)(int array[], int size);
typedef int *(*sorting_func2) (int array[], int size);

void process_args(int argc, char *argv[], sorting_func sort, sorting_func2 sort2) {

	int i = 0, array[argc];

	for (i = 0; i < argc; i++) 
		array[i] = strtol(argv[i], NULL, 10);

	if (sort) sort(array, argc);
	else if (sort2) sort2(array, argc);
	else printf("No sorting method provided...Printing out list: \n");
	
	for (i = 0; i < argc; i++)
		printf("%d  ", array[i]);

	printf("\n");

}


int find_lowest(int array[], int size, int start_index) {

        int i = 0, k = 0;

        for (i = start_index; i < size; i++) {

                int element = array[i], ret = 1;

                for (k = i + 1; k < size; k++) {

                        if (element > array[k]) {

                                ret = 0;
                                break;
                        }
                }

                if (ret)
                        break;
        }

        return i;

}

int *msort(int array[], int array2[], int size, int size2) {

	int *sorted_list = calloc(size + size2, sizeof(int)), i = 0, k = 0, j = 0;	

	if (sorted_list) {

		while (i < size && k < size2) {

			if (array[i] > array2[k]) sorted_list[j++] = array2[k++];
			else sorted_list[j++] = array[i++];
		}

		while (i < size) sorted_list[j++] = array[i++];
		while (k < size2) sorted_list[j++] = array2[k++];

	} else {

		sorted_list = NULL;
	}


	return sorted_list;
}

#endif
