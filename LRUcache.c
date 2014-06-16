/*Problem:
  Design and implement a data structure for Least Recently Used (LRU) cache.
  It should support the following operations: get and set.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int value;
    struct node *next;
};
struct node *top=NULL;
int max = 4; /*default*/
int size = 0;
void LRUCache(int capacity)
{
    max = capacity;
}

/*Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.*/
int get(int key)
{
    struct node *cur = top, *prev = NULL;
    while (cur) {
        if (cur->key == key) { /*hit*/
            int value = cur->value;
            if (cur == top) { /*top*/
                /*do nothing*/
            } else if (cur->next == NULL) { /*tail*/
                if (prev) {
                    prev->next = NULL;
                    cur->next = top;
                    top = cur;
                }
            } else { /*somewhere in middle*/
                prev = cur->next;
                cur->next = top;
                top = cur;
            }
            return value;
        }
        prev = cur;
        cur = cur->next;
    }
    return -1;
}
/*Set or insert the value if the key is not already present. When the cache reached its capacity,
it should invalidate the least recently used item before inserting a new item
*/
void set(int key, int value)
{
    int probe = get(key);
    if (probe == -1) { /*key not existed*/
        struct node *cur = malloc(sizeof(struct node));
        cur->key = key, cur->value = value, cur->next = top, top = cur; size+=1;
        if (size > max) {
            struct node *prev, *tail;
            while (cur) { /*move to tail-1*/
                prev = cur;
                if ((cur->next != NULL) && (cur->next->next == NULL)) {
                    tail = cur->next;
                    prev->next = NULL;
                    free(tail);
                    size-=1;
                    return;
                }
                cur = cur->next;
            }
            tail = prev;
        } 
    } else {  /*key existed*/
        if (probe == value) return;
        else top->value = value;
    } 
}
int main(void)
{
    printf("get(1)=%d size=%d\n", get(1), size);
    set(1, 2);
    printf("get(1)=%d size=%d\n", get(1), size);
    set(2, 3);
    printf("get(2)=%d size=%d\n", get(2), size);
    set(3, 4), set(4, 5), set(5, 6);
    printf("get(5)=%d size=%d\n", get(5), size);
    printf("get(1)=%d size=%d\n", get(1), size);
    return 0;
}