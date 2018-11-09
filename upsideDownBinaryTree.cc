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
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		TreeNode *p = root, *parent = nullptr, *parentRight = nullptr;
		while (p != nullptr) {
			TreeNode* left = p->left;	// save
			p->left = parentRight;
			parentRight = p->right;
			p->right = parent;
			p = left;			// step left
		}
		return parent;
	}
};

int main() {
    return 0;
}
