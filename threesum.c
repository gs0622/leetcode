#include <stdio.h>
#include <stdlib.h>

struct triple {int x,y,z;};
struct node {long long k; struct triple t; struct node *l, *r;};

void insert(struct node **ref, long long key, struct triple t)
{
	struct node *p = *ref;
	if (!p) {
		struct node *n = malloc(sizeof(struct node));
		n->k = key, n->l = n->r = NULL;
		n->t = t;
		*ref = n;
		return;
	}
	if (key == p->k) {
		printf("dup: %d %d %d\n", t.x, t.y, t.z);
		return; // skip duplicate
	}
	if (key > p->k) insert(&(p->r), key, t);
	else insert(&(p->l), key, t);
}

void inorder(struct node *n)
{
	if (!n) return;
	inorder(n->l);
	//printf("%d %d %d\n", n->t.x, n->t.y, n->t.z);
	inorder(n->r);
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
	int i, j, k, s, m, n = numsSize, *a = nums;
	struct node *h = NULL;
	for (i=0; i<n-3; i++) {
		j = i+1, k=n-1;
		while (k>j) {
			s = a[i]+a[j]+a[k]; // sum
			if (s == 0) {
				struct triple t = {a[i], a[j], a[k]};
				j++, k--;
				printf("sum: %d %d %d\n", t.x, t.y, t.z);
				m = a[i]*2+a[j]*3+a[k]*5;
				insert(&h, m, t);
			}
			else if (s<0) j++;
			else if (s>0) k--;
		}
	}
	inorder(h);
}

int cmp(const void *p, const void *q)
{
	return *((int *)p) - *((int *)q);
}

int main(void)
{
	int i, arr[] = {-1, 0, 1, 2, -1, -4};
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), cmp);
	threeSum(arr, sizeof(arr)/sizeof(int), NULL);
}

