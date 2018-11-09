#include <cstddef>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    TreeNode *prev;
    void postorder(TreeNode* root) {
        if (!root) return;
        postorder(root->right);
        postorder(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
public:
    void flatten(TreeNode* root) {
        prev = nullptr;
        postorder(root);
    }
};

int main(void) {
    TreeNode n1(1), n2(2);
    n1.left = &n2;
    Solution s;
    TreeNode *p = &n1;
    s.flatten(&n1);
    return 0;
}
