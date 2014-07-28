/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  07/06/2014 06:56:42 PM
 *
 *    Description:  implement merge sort in C
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 12
#define MIN(A, B) ((A < B) ? (A) : (B))

void merge(int a[], int na, int b[], int nb, int c[]) {
	int i, j, k;

	/*illustration*/
	printf("Before merge: subarray1\n");
	for (i = 0; i < na; i++)
		printf("%d ", a[i]);
	printf("\n");
	printf("Before merge: subarray2\n");
	for (i = 0; i < nb; i++)
		printf("%d ", b[i]);
	printf("\n");

	i = j = k = 0;
	while (i < na && j < nb) {
		if (a[i] <= b[j]) //keep stable
			c[k++] = a[i++];
		else 
			c[k++] = b[j++];
	}
	while (i < na)
		c[k++] = a[i++];
	while (j < nb)
		c[k++] = b[j++];
	
	/*illustration*/
	printf("After merge\n");
	for (i = 0; i < k; i++) {
		printf("%d ", c[i]);
	}
	printf("\nk is %d\n", k);
}

void Mergesort(int a[], int num) {
	int i;
	int *left, *right;
	int nl, nr;

	if (num < 2)
		return;

	//divide array a[] into 2 arraies left &right
	nl = (num + 1) / 2;
	nr = num - nl;
	left  = (int *)malloc(nl * sizeof(int));
	right = (int *)malloc(nr * sizeof(int));

	//move half of elements to left, the rest of elements to right
	printf("Left subarray is :\n");
	for (i = 0; i < nl; i++) {
		left[i] = a[i];
	/*illustration*/
		printf("%d ", left[i]);
	}
	printf("\n");
	printf("Right subarray is: \n");
	for (i = 0; i < nr; i++) {
		right[i] = a[nl + i];
	/*illustration*/
		printf("%d ", right[i]);
	}
	printf("\n");

	//recursive call
	Mergesort(left, nl);//a[] is changed into subarray left[]
	Mergesort(right, nr);//a[] is changed into subarray right[]

	merge(left, nl, right, nr, a);
	free(left);
	free(right);
}

/*bottom-up mergesort*/
/*
int min (int a, int b) {
	return ((a < b) ? a: b);
}
*/

void mergeBU (int a[], int lo, int mid, int last) {
	int i; 
	int nl, nr;
	int *left, *right, *temp;
	int n = last - lo + 1;

	printf("merge(array, %d, %d, %d)\n", lo, mid, last);
	/*creat 2 subarrays*/
	nl = mid + 1 -lo; 
	nr = last - mid;
	temp  = (int *)malloc(n * sizeof(int));
	left  = (int *)malloc(nl * sizeof(int));
	right = (int *)malloc(nr * sizeof(int));
	for (i = 0; i < nl; i++) 
		left[i] = a[i + lo];
	for (i = 0; i < nr; i++)
		right[i] = a[i + nl + lo];

	merge(left, nl, right, nr, temp);

	for (i = 0; i < n; i++) //copy the result from temp array
		a[lo + i] = temp[i];

	free(temp);
	free(left);
	free(right);
	
}

void mergesortBU (int a[], int num) {
	int sz = 1, lo;

	for (sz = 1; sz < num; sz *= 2) {
		printf("size is %d: \n", sz);
		for (lo = 0; lo < num - sz; lo += sz * 2) {
			printf("cursor is %d\n", lo);
			mergeBU(a, lo, lo+sz-1, MIN(lo+sz*2-1, num-1));
		}
	}
	printf("This is bottom-up merge sort.\n");
}


main (int argc, char *argv[]) {
	int i;
	int array[] = {82, 49, 70, 83, 68, 44, 94, 40, 32, 10, 99, 59};
	//don't forget to update LEN when this array is modified

	if (argc == 1)
		Mergesort(array, LEN);
	else if (argv[1][1] == 'b')
		mergesortBU(array, LEN);
	else
		printf("Illegal option.\n");

	for (i = 0; i < LEN; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}
