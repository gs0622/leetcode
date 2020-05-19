#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};
class Solution {
public:
	bool isCompleteTree1(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		while (q.size()) {
			TreeNode *cur = q.front(); q.pop();
			if (cur->left == nullptr) {
				if (cur->right != nullptr)
					return false;
				break;	// first nullptr 
			}
			q.push(cur->left);
			if (cur->right == nullptr)
				break;	// first nullptr
			q.push(cur->right);
		}
		while (q.size()) {
			TreeNode *cur = q.front(); q.pop();
			if (cur->left != nullptr || cur->right != nullptr)
				return false;
		}
		return true;
	}
	// flat level-order
	bool isCompleteTree(TreeNode* root) {
		vector<TreeNode*> bfs(1,root);
		size_t i=0;	// node
		while (i<bfs.size() && bfs[i]) {
			bfs.push_back(bfs[i]->left);
			bfs.push_back(bfs[i]->right);
			++i;
		}
		while (i<bfs.size()&& !bfs[i]) ++i;
		return i==bfs.size();
	}
};
void test1(){
	Solution s;
/*
           1
       2       3
     4   5   6   xb
    x x x x x x
*/
	TreeNode n6(6), n5(5), n4(4), n3(3,&n6,nullptr), n2(2,&n4,&n5), n1(1,&n2,&n3);
	cout << s.isCompleteTree1(&n1) << endl;
}
void test2(){
	Solution s;
/*
           1
       2       3b
     4   5   x   7
    x x x x     x x
*/
	TreeNode n7(7), n5(5), n4(4), n3(3,nullptr,&n7), n2(2,&n4,&n5), n1(1,&n2,&n3);
	cout << s.isCompleteTree1(&n1) << endl;
}
void test3(){
	Solution s;
/*
           1
       2       3b
     4   5   6   x
    x 9 x x x x
*/
	TreeNode n6(6), n5(5), n9(9), n4(4,nullptr,&n9), n3(3,&n6,nullptr), n2(2,&n4,&n5), n1(1,&n2,&n3);
	cout << s.isCompleteTree1(&n1) << endl;
}
int main(){
	test1();
	test2();
	test3();
}
