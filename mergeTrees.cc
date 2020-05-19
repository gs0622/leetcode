struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution2 {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return t2;
    if (t2) { // t1 && t2
      t1->val += t2->val;
      t1->left = mergeTrees(t1->left, t2->left);
      t1->right = mergeTrees(t1->right, t2->right);
    }
    return t1; // t1 or nullptr
  }
};
class Solution {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 && t2) {
      TreeNode* cur = new TreeNode(t1->val + t2->val);
      cur->left = mergeTrees(t1->left, t2->left);
      cur->right = mergeTrees(t1->right, t2->right);
      return cur;
    } else
      return t1? t1: t2;
  }
};
int main(){
}
