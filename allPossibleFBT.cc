/* https://leetcode.com/problems/all-possible-full-binary-trees/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {	// 1<=N<=20
	unordered_map<int, vector<TreeNode*>> mp;
public:
	vector<TreeNode*> allPossibleFBT1(int N) {
		vector<TreeNode*> res;
		if (mp.count(N)) return mp[N];				// cache
		if (N==1) {	// terminal case
			res.push_back(new TreeNode(0));
			mp[1]=res;
			return res;
		}
		--N;
		for (int i=1; i<N; i+=2) {
			vector<TreeNode*> L = allPossibleFBT(i);	// L would be 1, 3, 5... N-1 etc?
			vector<TreeNode*> R = allPossibleFBT(N-i);	// R would be N-1, N-3, N-5...?
			for (auto l: L) {
				for (auto r: R) {
					TreeNode* cur = new TreeNode(0);
					cur->left = l, cur->right = r;
					res.push_back(cur);
				}
			}
		}
		mp[N]=res;
		return res;
	}
	vector<TreeNode*> allPossibleFBT(int N) {
		vector<TreeNode*> res;
		if (N==1) {	// terminal case
			res.push_back(new TreeNode(0));
			return res;
		}
		--N;
		for (int i=1; i<N; i+=2) {
			vector<TreeNode*> L = allPossibleFBT(i);	// L would be 1, 3, 5... N-1 etc?
			vector<TreeNode*> R = allPossibleFBT(N-i);	// R would be N-1, N-3, N-5...?
			for (auto l: L) {
				for (auto r: R) {
					TreeNode* cur = new TreeNode(0);
					cur->left = l, cur->right = r;
					res.push_back(cur);
				}
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<TreeNode*> res;
	res = s.allPossibleFBT1(7);
	cout << res[0]->val << endl;
}

