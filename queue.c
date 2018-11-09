#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct queue {
	struct node *head;
	struct node *tail;
	int size;
};

void push(struct node **ref, int data)
{
	struct node *n = malloc(sizeof(struct node));
	n->data = data, n->next = *ref;
	*ref = n;
}

void move(struct node **dst, struct node **src)
{
	struct node *n = *src;
	*src = n->next;
	n->next = *dst;
	*dst = n;
}

void enqueue(struct queue *q, int data)
{
	struct node *n = calloc(1, sizeof(struct node));
	n->data = data;
	if (0 == q->size) q->tail = q->head = n;
	else {
		q->tail->next = n;
		q->tail = n;
	}
	q->size += 1;
}

void dequeue(struct queue *q)
{
	struct node *n = q->head;
	if (1 == q->size)
		q->head = q->tail = NULL;
	else
		q->head = n->next;
	free(n);
	q->size -= 1;
}

int main(void)
{
	struct queue q = {};
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	dequeue(&q);
	return 0;
}

