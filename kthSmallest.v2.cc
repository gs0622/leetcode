#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		TreeNode *cur = root;
		stack<TreeNode *> parent;
		while (true) {  // while (cur && stk.size())
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
};
int main(){
	TreeNode ro(7);
	TreeNode ll(3);
	TreeNode rr(11);
	TreeNode lll(1);
	TreeNode rrr(13);
	ro.left = &ll, ro.right = &rr;
	ll.left = &lll;
	rr.right = &rrr;
	Solution s;
	cout << s.kthSmallest(&ro, 1) << endl;
	cout << s.kthSmallest(&ro, 2) << endl;
	cout << s.kthSmallest(&ro, 3) << endl;
	cout << s.kthSmallest(&ro, 4) << endl;
	cout << s.kthSmallest(&ro, 5) << endl;
}

