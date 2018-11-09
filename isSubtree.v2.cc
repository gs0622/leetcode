/* https://leetcode.com/problems/subtree-of-another-tree/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode (int v): val(v), left(nullptr), right(nullptr) {}
};
struct node {
	int val;
	struct node *left, *right;
	string hash;
};

class Solution {
private:
	string hash(node *s) {
		if (!s) return "";
		std::hash<string> h;
		string ss = hash(s->left) + hash(s->right) + to_string(s->val); // postorder dfs
		s->hash = h(ss);
		return s->hash;
	}
	bool dfs(node *s, node *t) {
		if (!s) return false;
		return (s->hash == t->hash) ||
			dfs(s->left, t) || dfs(s->right, t);
	}
public:
	// O(s+t)
	bool isSubtree(node* s, node* t) {
		hash(s);
		hash(t);
		return dfs(s,t);
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
	//so.hash(s);
	//so.hash(t);
	bool r = so.isSubtree(s, t);
	cout << r << endl;
	return 0;
}
