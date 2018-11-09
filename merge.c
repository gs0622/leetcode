#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **ref, int data)
{
	// assert(*ref);
	struct node *n = malloc(sizeof(struct node));
	n->data = data, n->next = *ref;
	*ref = n;
}

void queue(struct node **ref, int data)
{
	// assert(*ref);
	struct node *n = malloc(sizeof(struct node));
	struct node dummy = {}, *m = &dummy;
	dummy.next = *ref;
	n->data = data, n->next = NULL;
	while (m->next) m = m->next;
	m->next = n;
	*ref = dummy.next;
}

void move(struct node **dst, struct node **src)
{
	// assert(*src);
	struct node *n = *src;
	*src = n->next; // *src->next
	n->next = *dst;
	*dst = n;
}

void append(struct node **dst, struct node **src)
{
	// assert(*src);
	struct node *n = *src, *m = *dst;
	while (m->next) m = m->next;
	*src = n->next;
	n->next = NULL;
	m->next = n;
}

struct node* merge(struct node* a, struct node* b)
{
	struct node dummy = {};
	struct node *tail = &dummy;
	if (!a) return b;
	if (!b) return a;
	while (1) {
		if (!a) { tail->next = b; break; };
		if (!b) { tail->next = a; break; };
		if (a->data < b->data) {
			tail->next = a, tail = a;
			a = a->next;
		} else {
			tail->next = b, tail = b;
			b = b->next;
		}
	}
	return dummy.next;
}

int main(void)
{
	struct node *a = NULL;
	struct node *b = NULL;
	struct node *p;
	queue(&a, 1), queue(&a, 2);
	queue(&b, 3), queue(&b, 4);
	p = merge(a, b);
	;
}
