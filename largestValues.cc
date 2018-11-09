#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {}
};
class Solution {
public:
	vector<int> largestValues1(TreeNode* root) {
		vector<int> res;
		function<void(TreeNode*,int)> helper = [&](TreeNode* cur, int d) {
			if (!cur) return;			// terminal
			if (d==res.size())			// preorder
				res.push_back(cur->val);	// append
			else
				res[d] = max(res[d], cur->val);	// replace
			helper(cur->left, d+1);
			helper(cur->right, d+1);
		};
		helper(root, 0);
		return res;
	}
	// level-order traversal, along w/ maxheap
	vector<int> largestValues(TreeNode* root) {
		if (!root) return {};
		vector<int> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			priority_queue<int> pq;
			int n = q.size();
			for (int i=0; i<n; ++i) {
				TreeNode *cur = q.front(); q.pop();
				pq.push(cur->val);
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			res.push_back(pq.top());
		}
		return res;
	}
};
int main(){
	Solution s;
	TreeNode n5(5), n30(3), n9(9), n31(3,&n5,&n30), n2(2,nullptr,&n9), n1(1,&n31,&n2);
	vector<int> res;
	res = s.largestValues(&n1);
	for_each(begin(res), end(res), [](int n){cout << n << ' ';}); cout << endl;
	res = s.largestValues1(&n1);
	for_each(begin(res), end(res), [](int n){cout << n << ' ';}); cout << endl;
}
