#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		map<int,map<int,set<int>>> mp;
		function<void(TreeNode*,int,int)> helper=[&](TreeNode* cur, int x, int y) {
			if (!cur) return;
			mp[x][y].insert(cur->val);
			helper(cur->left, x-1,y+1);
			helper(cur->right, x+1,y+1);
		};
		helper(root,0,0);
		vector<vector<int>> res;
		for (auto p: mp) {
			res.push_back(vector<int>());
			for (auto q: p.second)
				res.back().insert(res.back().begin(), q.second.begin(), q.second.end());
		}
		return res;
	}
};
int main(){
}
