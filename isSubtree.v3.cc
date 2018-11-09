#include <functional>
#include <iostream>
#include <string>
#include <openssl/sha.h>
using namespace std;

#ifdef __cplusplus
extern "C"{
#endif 
unsigned char *SHA256(const unsigned char *d, size_t n,unsigned char *md);
#ifdef __cplusplus
}
#endif

struct node {
    int val;
    struct node *left, *right;
    string merkle;
};

class Solution {
private:
public:
    string merkle(node *n) {
        if (!n) return 0;
        string s;
        s = merkle(n->left) + merkle(n->right) + to_string(n->val);
        unsigned char buf[32];
        unsigned char *in = (unsigned char *)s.c_str();  
        SHA256(in, s.size(), buf);
        string r((const char *)buf);
        n->merkle = r;
        return r;
    }
	// O(s+t)
	bool isSubtree(node* s, node* t) {
		if (!s) return false;
		return (s->merkle == t->merkle) ||
		isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};

int main(void) {
    struct node ss[7]= {{3,0,0}, {4,0,0}, {1,0,0}, {2,0,0}, {5,0,0}, {0,0,0}};
    struct node tt[7]= {{4,0,0}, {1,0,0}, {2,0,0}};
    struct node *s = &ss[0];
    struct node *t = &tt[0];
    s->left = &ss[1], s->right = &ss[4];
    s->left->left = &ss[2], s->left->right = &ss[3];
    t->left = &tt[1];
    t->right = &tt[2];
    Solution so;
    so.merkle(s);
    so.merkle(t);
    bool r = so.isSubtree(s, t);
    cout << r << endl;
    return 0;
}
