#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	void helper(TreeNode *cur, int depth, vector<vector<int>>& res) { // DFS
		if (!cur) return;
		// tricky: when first-time in this level, size will +1 hence further return will not skip re-create
		if (res.size()==depth) res.push_back(vector<int>()); // preorder?
		res[depth].push_back(cur->val);
		helper(cur->left, depth+1, res);
		helper(cur->right, depth+1, res);
	}
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		helper(root, 0, res);
		return res;
	}
	vector<vector<int>> levelOrder2(TreeNode* root) {
                if (!root) return vector<vector<int>>();
                vector<vector<int>> res;
                queue<TreeNode *> q;
                q.push(root);
                res.push_back(vector<int>{root->val});
                while (!q.empty()) {
                        vector<int> ans;
                        int i, sz = q.size();
                        for (i=0; i<sz; ++i) {
                                TreeNode* p = q.front();
                                q.pop();
                                if (p->left) {
                                        q.push(p->left);
                                        ans.push_back(p->left->val);
                                }
                                if (p->right) {
                                        q.push(p->right);
                                        ans.push_back(p->right->val);
                                }
                        }
                        if (!ans.empty()) res.push_back(ans);
                }
                return res;
	}
};
int main(){
	Solution s;
	TreeNode n1(3);
	TreeNode n2(9);
	TreeNode n3(20);
	TreeNode n4(15);
	TreeNode n5(17);
	TreeNode n6(1);
	TreeNode n7(2);
	n1.left=&n2, n1.right=&n3;
	n3.left=&n4, n3.right=&n5;
	n4.left=&n6, n5.right=&n7;
	vector<vector<int>> r=s.levelOrder(&n1);
	for (auto lv: r) {
		for (auto v: lv) cout << v << " ";
		cout << endl; // gdb marker
	}
}
