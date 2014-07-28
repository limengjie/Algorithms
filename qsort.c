/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  06/02/2014 07:28:49 PM
 *
 *    Description:  quick sort
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100
#define LEN 12

void quicksortBK(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);


	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	printf("left is %d\n", v[left]);
	printf("last is %d\n", v[last]);
	swap(v, left , last);
	printf("first half\n");
	for (i = left; i < last; i++)
		printf("%d\n", v[i]);
	printf("second half\n");
	for (i = last + 1; i < right + 1; i++)
		printf("%d\n", v[i]);
	quicksortBK(v, left, last - 1);
	/*for (i = left; i < last; i++)*/
		/*printf("%d\n", v[i]);*/
	quicksortBK(v, last + 1, right);
	/*for (i = last + 1; i < right + 1; i++)*/
		/*printf("%d\n", v[i]);*/
}

void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int intcmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int partition (int a[], int lo, int hi) {
	int i = lo, j = hi + 1;
	int k;

	/*illustration*/
	printf("Before partition: \n");
	for (k = 0; k < LEN; k++) {
		if (k == lo)
			printf("( ");
		if (k == hi + 1)
			printf(") ");
		printf("%d ", a[k]);
	}
	printf("\n");
	printf("Compared with %d.\n", a[lo]);

	for (;;) {
		while (a[++i] < a[lo]) {
			if (i >= hi)
				break;
	}
		while (a[--j] > a[lo]) {
			if (j <= lo)
				break;
		}
		if (i >= j)
			break;
		swap(a, i, j);

	/*illustration*/
		printf("i= %d j= %d\n", i, j);
	}
	swap(a, lo, j);

	/*illustration*/
	printf("After partition: \n");
	for (k = 0; k < LEN; k++) {
		if (k == lo)
			printf("( ");
		if (k == hi + 1)
			printf(") ");
		printf("%d ", a[k]);
	}
	printf("\nj= %d, a[j]= %d\n", j, a[j]);

	return j;
}
	

void quicksort (int a[], int lo, int hi) {
	int j;

	if (hi <= lo)
		return;
	j = partition(a, lo, hi);
	quicksort(a, lo, j - 1);
	quicksort(a, j + 1, hi);
}

void quicksort3way (int a[], int lo, int hi) {
	int i = lo, lt = lo, gt = hi;
	int v = a[lo], k;
	
	if (hi <= lo)
		return;
	/*illustration*/
	printf("\nBefore swap.\n");
	for (k = 0; k < LEN; k++) {
		if (k == lo)
			printf("( ");
		if (k == hi + 1)
			printf(") ");
		if (k == lt)
			printf("lt ");
		if (k == gt)
			printf("gt ");
		if (k == i)
			printf("i ");
		printf("%d ", a[k]);
	}
	printf("\n");
	while (i <= gt)
	{
		if (a[i] < v) {
			printf("\n%d < v=%d i++ lt++ \n", a[i], v);
			swap(a, lt++, i++);
			/*illustration*/
			for (k = 0; k < LEN; k++){
				if (k == lo)
					printf("( ");
				if (k == hi + 1)
					printf(") ");
				if (k == lt)
					printf("lt ");
				if (k == gt)
					printf("gt ");
				if (k == i)
					printf("i ");
				printf("%d ", a[k]);
			}
		}
		else if (a[i] > v) {
			printf("\n%d > v=%d gt-- \n", a[i], v);
			swap(a, i, gt--);
			/*illustration*/
			for (k = 0; k < LEN; k++){
				if (k == lo)
					printf("( ");
				if (k == hi + 1)
					printf(") ");
				if (k == lt)
					printf("lt ");
				if (k == gt)
					printf("gt ");
				if (k == i)
					printf("i ");
				printf("%d ", a[k]);
			}
		}
		else {
			printf("\n%d == v=%d i++ \n", a[i], v);
			i++;
			/*illustration*/
			for (k = 0; k < LEN; k++){
				if (k == lo)
					printf("( ");
				if (k == hi + 1)
					printf(") ");
				if (k == lt)
					printf("lt ");
				if (k == gt)
					printf("gt ");
				if (k == i)
					printf("i ");
				printf("%d ", a[k]);
			}
		}
		if (i > gt)
			printf("\ni and gt cross.\n");
	}

	quicksort3way(a, lo, lt - 1);
	quicksort3way(a, gt + 1, hi);
}

main (int argc, char *argv[]) {
	int i;
	int array[LEN] = {1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 1, 2};
	/*don't forget to update the LEN of the array if it is modified*/

	
	if (argc == 1) {
		quicksort(array, 0 , LEN - 1);
	}
	else if (argc == 2) {
		if (strcmp(argv[1], "-b") == 0) {
			printf("This is a built-in function.\n");
			qsort(array, LEN, sizeof(int), intcmp);
		}
		else if (strcmp(argv[1], "-t") == 0) {
			printf("Three way quick sort: \n");
			quicksort3way(array, 0, LEN-1);
		}
		else
			printf("Illegal options.\n");
	}
	printf("\n++++++++++++++++++++++++++++++++\n");
	for (i = 0; i < LEN; i++)
		printf("%d ", array[i]);
	printf("\n++++++++++++++++++++++++++++++\n");
}
