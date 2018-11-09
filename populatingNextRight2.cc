#include <bits/stdc++.h>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int v): val(v), left(nullptr), right(nullptr), next(nullptr) {}
};
/*

*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode *cur=root, *head, *tail;
		head=tail=nullptr;
		while (cur) {
			if (cur->left)
				if (tail) tail->next=cur->left, tail=tail->next;
				else head=tail=cur->left;
			if (cur->right)
				if (tail) tail->next=cur->right, tail=tail->next;
				else head=tail=cur->right;
			cur = cur->next;
			if (!cur) {
				cur=head;
				head=tail=nullptr;
			}
		}
	}
};
int main(){
	
}
