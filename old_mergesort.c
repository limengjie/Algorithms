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

#define LEN 8

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
		if (a[i] < b[j])
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
	nl = num / 2;
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
int min (int a, int b) {
	return ((a < b) ? a: b);
}

void mergeBU (int a[], int lo, int last) {
	int i, j, k; 
	int nl, nr;
	int *left, *right;
	int n = last - lo + 1;

	nl = n / 2;
	nr = n - nl;
	left  = (int *)malloc(nl * sizeof(int));
	right = (int *)malloc(nr * sizeof(int));

	for (i = 0; i < nl; i++)
		left[i] = a[i + lo];
	for (i = 0; i < nr; i++)
		right[i] = a[i + nl + lo];

	
	/*illustration*/
	printf("Before merge: subarray1\n");
	for (i = 0; i < nl; i++)
		printf("%d ", left[i]);
	printf("\n");
	printf("Before merge: subarray2\n");
	for (i = 0; i < nr; i++)
		printf("%d ", right[i]);
	printf("\n");

	i = j = 0;
	k = lo;
	while (i < nl && j < nr) {
		if (left[i] < right[j])
			a[k++] = left[i++];
		else 
			a[k++] = right[j++];
	}
	while (i < nl)
		a[k++] = left[i++];
	while (j < nr)
		a[k++] = right[j++];
	
	/*illustration*/
	printf("After merge\n");
	for (i = 0; i < LEN; i++) {
		if (i == k)
			printf("after k elements: ");
		printf("%d ", a[i]);
	}
	printf("\nk is %d\n", k);
	free(left);
	free(right);
	
}

void mergesortBU (int a[], int num) {
	int sz = 1, lo;
	for (sz = 1; sz < num; sz *= 2) {
		printf("size is %d: \n", sz);
		for (lo = 0; lo < num - sz; lo += sz * 2) {
			printf("cursor is %d\n", lo);
			mergeBU(a, lo, min(lo + sz*2 -1, num - 1));
		}
	}
}


main () {
	int i;
	int len = 8, array[] = {9, 8, 3, 6, 5, 4, 7, 2};

	mergesortBU(array, len);

	for (i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");
	
	/*printf("min is %d\n", min(29, 121));*/

	return 0;
}
