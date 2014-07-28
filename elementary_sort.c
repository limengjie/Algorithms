/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  07/03/2014 07:20:08 PM
 *
 *    Description: implement several elementary sort algorithms in C 
 *
 * ===========================================================================
 */

#include <stdio.h>

int swap (int *array, int i, int j) {
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;

	return 1;//ex
}

void selSort (int *array, int len) {
	int i, j, min;
	
	printf("This is selection sort:\n");

	for (i = 0; i < len; i++) {
		min = i;
		for (j = i; j < len; j++)
			if (array[j] < array [min])
				min = j;
		swap(array, i, min);
	}
}

/*
void inserSort (int *array, int len) {
	int i, j, n_exch = 0;

	for (i = 0; i < len; i++) {
		for (j = i; j > 0; j--) {
			if (array[j] < array[j-1]) {
				swap(array, j, j-1);
				n_exch++;
				if (n_exch == 6)
					return;
			}
			else break;
		}
	}
}
*/

void h_Sort (int *a, int len, int h) {
	int i, j;

	/*printf("h is %d\n", h); */

	for (i = h; i < len; i++) {
		for (j = i; j >= h && a[j] < a[j-h]; j -= h) {
			swap(a, j, j-h);
		}
	}
}

void insSort (int *array, int len) {
	int h = 1;

	printf("This is insertion sort:\n");
	h_Sort(array, len, h);
}

void shellSort (int *a, int len) {
	int h = 1;
	int i;

	printf("This is shell sort:\n");
	while (h < len/3)
		h = 3*h + 1;

	/*printf("h is %d\n", h);*/
	while (h >= 1) {
		h_Sort (a, len, h);
		h = h / 3;
	}
	/*printf("shellsort ends\n");*/
	/*for (i = 0; i < len; i++)*/
		/*printf("%d ", a[i]);*/
}

main (int argc, char *argv[]) {
	int i, n = 10, num,  a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int b[] = {46, 30, 76, 56, 62, 22, 23, 51, 47, 16};
	int c;

	if (argc == 1)
		shellSort(b, n);
	else if (argv[1][0] == '-') {
		if (c = (argv[1][1]))
			switch (c) {
				case 's':
					selSort(b, n);
					break;
				case 'i':
					insSort(b, n);
					break;
				default:
					printf("Illegal option %c\n", c);
					break;

			}
	}

	for (i = 0; i < n; i++)
		printf("%d ", b[i]);
}
