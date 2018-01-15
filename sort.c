#include "sorting_algorithms.h"
#include "extra_functions.h"


int main(int argc, char *argv[]) {

	if (argc < 3) {

		fprintf(stderr, "Usage: ./sort [algorithm] [list]\n");
		return -1;
	}

	sorting_func s = NULL;
	sorting_func2 s2 = NULL;

	if (!strcmp(argv[1], "quicksort") || !strcmp(argv[1], "mergesort")) {

		if (!strcmp(argv[1], "quicksort")) s2 = quicksort;
		else s2 = merge_sort;
		
	} else if (!strcmp(argv[1], "bubble_sort")) {

		s = bubble_sort;

	} else if (!strcmp(argv[1], "insertion_sort")) {

		s = insertion_sort;

	} else if (!strcmp(argv[1], "selection_sort")) {

		s = selection_sort;
	} 
	
	if (s2) process_args(argc - 2, argv + 2, NULL, s2);
	else if (s) process_args(argc - 2, argv + 2, s, NULL);
	else fprintf(stderr, "I don't know that sorting algorithm :p\n");


	return 0;

}
