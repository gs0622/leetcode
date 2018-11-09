/*Problem:
  Design and implement a data structure for Least Recently Used (LRU) cache.
  It should support the following operations: get and set.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
	int key;
	int value;
	struct node *next;
	struct node *prev;
};
struct queue {
	struct node *head;
	struct node *tail;
	int size;
};
struct queue q = {};
int max = 32; /*default*/
int size = 0;
/* push to queue head */
void push(struct queue *q, int key, int value)
{
	struct node *n = calloc(1, sizeof(struct node));
	n->key = key, n->value = value, n->next = q->head;
	if (q->head) q->head->prev = n;
	else q->tail = n;
	q->head = n;
	q->size += 1;
}
/* pop from head */
int pop(struct queue *q) 
{
        assert(q->head);
        struct node *n = q->head;
        int value = n->value;
        q->head = q->head->next;
        if (q->head->next) q->head->next->prev = NULL;
        free(n);
	q->size -= 1;
        return value;
}
/* dequeue from tail */
int dequeue(struct queue *q) 
{
        assert(q->tail);
        struct node *n = q->tail;
        int value = n->value;
        q->tail = q->tail->prev;
        q->tail->next = NULL;
        free(n);
	q->size -= 1;
        return value;
}
void dump(struct queue *q)
{
	struct node *cur = q->head;
	while (cur) {
		printf("%d : %d\n", cur->key, cur->value);
		cur = cur->next;
	}
	printf("\n");
}
int search(struct queue *q, int key)
{
	struct node *cur = q->head;
	while (cur) {
		if (cur->key == key) return cur->value;
		cur = cur->next;
	}
	
}
unsigned int hash(int key)
{
        long long hash = (long long)key * 2564435761 % 4294967296;
        return (unsigned int )hash;
}
struct node *list[16] = {};
/*Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.*/
int get(int key)
{
	int a, b;
	unsigned int k = hash(key)%16;
	struct node *p = list[k];
	a = search(&q, key);
	b = p->value;
	printf("a=%d b=%d k=%d\n", a, b, k);
	return a;
}
/*Set or insert the value if the key is not already present. When the cache reached its capacity,
it should invalidate the least recently used item before inserting a new item
*/
void set(int key, int value)
{
	push(&q, key, value);
	printf("set: %d: %u\n", key, hash(key)%16);
	list[hash(key)%16] = q.head;
}
int main(void)
{
	set(1, 1);
	set(2, 2);
	//dump(&q);
	printf("%d\n", get(1));
	printf("%d\n", get(2));
	return 0;
}
