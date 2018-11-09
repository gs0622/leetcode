#include <stdio.h>
#include <stdlib.h>

typedef struct interval { int start, end; } interval_t;
typedef struct node { interval_t data; struct node *next; } node_t;

int cmp(const void *p, const void *q) {
    interval_t *pp = (interval_t *)p;
    interval_t *qq = (interval_t *)q;
    return (pp->start - qq->start);
}

void push(node_t **ref, interval_t data) {
    node_t *p = *ref;
    node_t *q= (node_t *)malloc(sizeof(node_t));
    q->data = data, q->next = NULL;
    if (!p) {
        *ref = q;
        return;
    }
    q->next = *ref;
    *ref = q;
}

int main(void) {
    int a, b, i, j, top = -1, top2 = -1;
    interval_t stack[100] = {};
    interval_t stack2[100] = {};
    while(scanf("(%d,%d),",&a,&b))
    {
        ++top;
        stack[top].start = a;
        stack[top].end = b;
    }

    qsort(&stack[0], top+1, sizeof(interval_t), cmp);
/*    for (i = 0; i <= top; i++) {
        interval_t *this = &stack[i];
        printf("%d-%d ", this->start, this->end); 
    }
    printf(": %d\n", top);*/

    for (i = 1; i <= top; i++) {
        interval_t *this = &stack[i];
        interval_t *last = &stack[i-1];
        if (this->start < last->end && this->end > last->end) {
                // merge overlapping
                interval_t merge;
                merge.start = last->start, merge.end = this->end;
                stack2[++top2] = merge;
        }
    }
    for (i = 0; i <= top2; i++) {
        interval_t *this = &stack2[i];
        printf("%d %d\n", this->start, this->end); 
    }
    return 0;
}
