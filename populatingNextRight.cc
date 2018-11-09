#include <bits/stdc++.h>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int v): val(v), left(nullptr), right(nullptr), next(nullptr) {}
};
class Solution {
public:
	void connect1(TreeLinkNode *root) {
		TreeLinkNode *cur=root, *head, *tail;
		head=tail=nullptr;
		while (cur) {
			if (cur->left)
				if (tail) tail=tail->next=cur->left;
				else head=tail=cur->left;
			if (cur->right)
				if (tail) tail=tail->next=cur->right;
				else head=tail=cur->right;
			cur = cur->next;
			if (!cur) {
				cur=head;
				head=tail=nullptr;
			}
		}
	}
	void connect(TreeLinkNode *root) {
		if (!root) return;
		queue<TreeLinkNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {
				TreeLinkNode *cur=q.front(); q.pop();
				if (i<n-1) cur->next = q.front();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right); 
			}
		}
	}
};
int main(){
	
}
