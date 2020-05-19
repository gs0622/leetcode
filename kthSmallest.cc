#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	int res;
	void inorder(TreeNode *cur, int& k) {
		if (!cur) return;
		inorder(cur->left, k);
		--k;
		if (k==0) {
			res = cur->val;
			return;
		}
		inorder(cur->right, k);
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		inorder(root, k);
		return res;
	}
        int kthSmallest1(TreeNode* root, int k) {
                TreeNode *cur = root;
                stack<TreeNode *> parent;
                while (true) {
                        if (cur) { // go left
                                parent.push(cur);
                                cur = cur->left;
                        } else { // backtrak one, go right once
                                if (!parent.empty()) {
                                        cur = parent.top();
                                        parent.pop();
                                        --k;
                                        if (k==0) return cur->val;
                                        cur = cur->right;
                                }
                        }
                     
                }
        }
  int kthSmallest2(TreeNode* root, int k) {
		TreeNode *cur=root;
		stack<TreeNode*> stk;
		while (cur || !stk.empty()) {
			while (cur) {
				stk.push(cur);
				cur=cur->left;
			}
			cur=stk.top(); stk.pop();
			--k;
			if (k==0) return cur->val;
			cur=cur->right;
		}
	}
};
int main(){
	TreeNode ro(7);
	TreeNode ll(3);
	TreeNode rr(11);
	TreeNode lll(5);
	TreeNode rrr(13);
	ro.left = &ll, ro.right = &rr;
	ll.right = &lll;
	rr.right = &rrr;
	Solution s;
	cout << s.kthSmallest2(&ro, 1) << endl;
	cout << s.kthSmallest2(&ro, 2) << endl;
	cout << s.kthSmallest2(&ro, 3) << endl;
	cout << s.kthSmallest2(&ro, 4) << endl;
	cout << s.kthSmallest2(&ro, 5) << endl;
}

