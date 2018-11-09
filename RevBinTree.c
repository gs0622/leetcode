#include <stdio.h>
#include <stdlib.h>

struct node { int d; struct node *l, *r; };

void push(struct node **ref, int data)
{
	struct node *n = malloc(sizeof(struct node));
	n->d = data, n->l = n->r = NULL;
	*ref = n;
}

void reverse(struct node **pp)
{
	if (!(*pp) || !((*pp)->l)) return;
	struct node *h = *pp;
	struct node *l = h->l;
	struct node *r = h->r;
	reverse(&(h->l));
	l->r = h, l->l = r;
	h->l = h->r = NULL;
	*pp = l;
}

int main(void)
{
	struct node dummy = { 1, NULL, NULL };
	struct node *h = &dummy;
	struct node *a = NULL;
	push(&(h->l), 2);
	push(&(h->r), 3);
	push(&(h->l->l), 4);
	push(&(h->l->r), 5);
	;
	reverse(&h);
	;
}

