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

struct Node * deleteMin(struct Node * x) {
	if (x->left == NULL)
		return x->right;
	x->left = deleteMin(x->left);
	x->count = 1 + size(x->left) + size(x->right);

	return x;
}

struct Node * min(struct Node * x) {
	if (x->left == NULL)
		return x;
	x = min(x->left);

	return x;
}

struct Node * delete(struct Node * x, char key) {
	int cmp;
	struct Node * t;

	if (x == NULL) 
		return NULL;
	cmp = key - x->key;
	if (cmp < 0)
		x->left = delete(x->left, key);//search for key
	else if (cmp > 0)
		x->right = delete(x->right, key);//search for key
	else if (cmp == 0) {//find the key
		printf("Delete node %c = %d\n", x->key, x->val);

		if (x->right == NULL) {
			printf("x-> == NULL\n");
			return x->left;
		}
		t = x;
		x = min(t->right);
		x->right = deleteMin(t->right);
		x->left = t->left;
	}
	x->count = size(x->left) + size(x->right) + 1;//update subtree count

	return x;
}

main () {
	char keys[] = {'S', 'E', 'A', 'R', 'C', 'H', 'E', 'X', \
		'A', 'M', 'P', 'L', 'E'};
	int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	struct Node * root = NULL, * p;
	int i;

	/*add new nodes to the tree*/
	for (i = 0; i < LEN; i++) {
		root = put(root, keys[i], values[i]);
	}

	printf("before deletion\n");
	treeprint(root);
	/*p = deleteMin(root);*/
	p = delete(root, 'E');
	printf("after deletion:\n");
	treeprint(root);

	return 0;
}
