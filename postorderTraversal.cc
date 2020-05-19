/**
 * Definition for a binary tree node.
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution2 {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    TreeNode *cur = root;
    stack<TreeNode*> s;
    deque<int> dq;
    while (cur || s.size()) {
      while (cur) {
        dq.push_front(cur->val);
        s.push(cur), cur=cur->right;
      }
      cur=s.top(), s.pop();
      cur=cur->left;
    }
    return vector<int>(dq.begin(),dq.end());
  }
};
class Solution {
public:
        vector<int> postorderTraversal(TreeNode *root) {
                if (!root) return {};
                TreeNode *cur = root;
                stack<TreeNode*> stk;
                vector<int> res;
                while (cur || !stk.empty()) {   // trick: reversed preorder traversal
                        while (cur) {
                                res.insert(begin(res), cur->val);       // O(n) -> better: deque.push_front (O(1))
                                stk.push(cur), cur = cur->right;
                        }
                        cur = stk.top(), stk.pop();
                        cur = cur->left;
                }
                return res;
        }
};
int main(){}
