/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  07/26/2014 06:32:18 PM
 *
 *    Description:  binary search tree
 *
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN 13

struct Node {
	char key;
	int val;
	struct Node * left;
	struct Node * right;
	int count;
};

int size(struct Node * x) {
	if (x == NULL)
		return 0;
	return x->count;
}

struct Node * put(struct Node *p, char key, int value) {
	int cmp;

	if (p == NULL) {
		p = (struct Node *) malloc(sizeof(struct Node));
		p->key = key;
		p->val = value;
		p->left = p->right = NULL;
		p->count = 1;
		printf("Add new node %c = %d\n", p->key, p->val);

		return p;
	}
	cmp = (key - p->key);
	if (cmp > 0) {
		p->right = put(p->right, key, value);
	}
	else if (cmp < 0) {
		p->left = put(p->left, key, value);
	}
	else if (cmp == 0) {
		p->val = value;
		printf("Update node %c = %d\n", p->key, p->val);
	}
	p->count = 1 + size(p->left) + size(p->right);

	return p;
}

void treeprint(struct Node * p) {
	if (p) {
		treeprint(p->left);
		printf("Key= %2c  Value= %2d count= %d\n", \
				p->key, p->val, p->count);
		treeprint(p->right);
	}
}

struct Node * findFloor(struct Node * x, char key) {
	int cmp;
	struct Node * t;

	if (x == NULL)
		return NULL;
	cmp = (key - x->key);
	if (cmp == 0)
		return x;
	else if (cmp < 0)
		return findFloor(x->left, key);

	t = findFloor(x->right, key);
	if (t)
		return t;
	else
		return x;

	return x;
}

main () {
	char keys[] = {'S', 'E', 'A', 'R', 'C', 'H', 'E', 'X', \
		'A', 'M', 'P', 'L', 'E'};
	int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	struct Node * root = NULL, * p;
	int i;

	for (i = 0; i < LEN; i++) {
		root = put(root, keys[i], values[i]);
	}
	treeprint(root);

	/*find floor function*/
	/*p = findFloor(root, 'F');*/
	/*printf("F's findFloor is %c = %d\n", p->key, p->val);*/
	return 0;
}
