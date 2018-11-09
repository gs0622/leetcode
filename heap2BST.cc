#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};
struct node *newnode(int key) {
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}
void insert(struct node **ref, int key) {
    struct node *n = *ref;
    if (!n) {
        n = newnode(key);
        *ref = n;
        return;
    }
    insert((key < n->key)? &(n->left): &(n->right), key);
}
int main(void) {
    int a[] = {10,20,30,5,15};
    vector<int> v(a, a+5);
    make_heap(v.begin(), v.end(), std::greater<int>());
    struct node *root = NULL;
    for (auto x: v) {
        cout << x << " ";
        insert(&root, x);
    }
    cout << endl;
    return 0;
}
