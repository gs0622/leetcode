#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};
class Solution2 {
public:
	string smallestFromLeaf(TreeNode* cur) {
		if (cur==nullptr) return "|";
		auto s = string(1, 'a'+cur->val);
		if (cur->left == cur->right) return s;	// both are in nullptr, which is leaf
		else return min(smallestFromLeaf(cur->left), smallestFromLeaf(cur->right)) + s;
	}
};
class Solution {
	const string alphabet{"abcdefghijklmnopqrstuvwxyz"};
	void helper(TreeNode* cur, string& s, vector<string>& r) {
		if (!cur) {
			return;
		}
		string t = s;
		t = alphabet[cur->val] + t;
		helper(cur->left, t, r);
		helper(cur->right, t, r);
		if (cur->left==cur->right)
			r.push_back(t);
	}
public:
	string smallestFromLeaf(TreeNode* root) {
		vector<string> r;
		string s;
		helper(root,s,r);
		sort(r.begin(), r.end());
		return *r.begin();
	}
};
int main(){
	Solution s;
	//TreeNode n7(4),n6(3),n5(4),n4(3),n3(2,&n6,&n7),n2(1,&n4,&n5),n1(0,&n2,&n3);
	//cout << s.smallestFromLeaf(&n1) << endl;
	TreeNode n5(16),n4(19),n3(7),n2(13,&n4,&n5),n1(23,&n2,&n3);
	cout << s.smallestFromLeaf(&n1) << endl;
}
