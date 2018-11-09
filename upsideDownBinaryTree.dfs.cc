/*

   1
  / \
  2 3
 / \
 4 5

   4
  / \
  5 2
   / \
   3 1

At each node you want to assign:
p.left = parent.right;
p.right = parent;
*/
#include <cstddef>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    TreeNode *dfsBottomUp(TreeNode *n, TreeNode *parent) {
        if (n == nullptr) return parent;
        TreeNode *p = dfsBottomUp(n->left, n);
        p->left = (parent != nullptr)? parent->right: nullptr;
        p->right = parent;
        return p;
    }
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return dfsBottomUp(root, nullptr);
    }   
};

int main() {
    return 0;
}
