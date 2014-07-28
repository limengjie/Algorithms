/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  07/22/2014 05:30:45 PM
 *
 *    Description:  Binary heaps
 *
 * ===========================================================================
 */

#include <stdio.h>
#define LEN 12

void swap (int array[], int i, int j) {
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void swim (int array[], int k) {
	while (k/2 >= 1 && array[k] > array[k/2]) {
		swap(array, k, k/2);
		k /= 2;
	}
}

void sink (int array[], int sz, int k) {
	int n;

	printf("sink array[%d]= %d to %d\n", k, array[k], sz-1);

	while (k * 2 < sz) { 
		n = k * 2;
		if (array[n] < array[n+1] && n+1 < sz) {
			printf("n = 2k + 1 = %d\n", n+1);
			n++;
		}
		if (array[k] >= array[n]) {
			printf("parent[%d] > child[%d], break\n", k, n);
			break;
		}
		printf("array[%d] = %d <-> array[%d] = %d\n",\
			k, array[k], n, array[n]);
		swap(array, k ,n);
		k = n;
	}
}

int delMax (int array[], int sz) {
	int max = array[1];

	printf("delete %d\n", array[1]);
	swap(array, 1, sz-1);
	sink(array, sz - 1, 1);//The array shrinks by 1 after \
	moving the largest one to the end of the array

	return max;
}

void maxHeap(int array[], int sz) {
	int i = (sz - 1) / 2;

	while (i > 0) {
		sink(array, sz, i--);
	}
}

void sortDown (int array[], int sz) {
	int n = sz, i;

	while (n > 1) {
		delMax(array, n--);
		printf("After del&sink, n= %d\n", n);
		for (i = 1; i < LEN; i++) {
			if (i == n)
				printf("del: ");
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}

void heapsort(int array[], int sz) {
	int i;

	maxHeap(array, sz);
	printf("Max heap is built.\n");
	for (i = 1; i < LEN; i++)
		printf("%d ", array[i]);
	printf("\n");
	sortDown(array, sz);
}
main () {
	int i;
	int array[] = {0, 19, 15, 18, 20, 5, 24, 1, 13, 16, 12, 5};
	//array[0] is meaningless
	int b[] = {0, 24, 20, 19, 16, 12, 18, 1, 13, 15, 5, 5};

	printf("The original array is: \n");
	for (i = 1; i < LEN; i++)
		printf("%d ", array[i]);
	printf("\n_________________________________\n");

	heapsort(array, LEN);

	printf("++++++++++++++++++++++++++++++++\n");
	for (i = 1; i < LEN; i++)
		printf("%d ", array[i]);
	printf("\n +++++++++++++++++++++++++++++++\n");
	return 0;
}
