/* https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
	// bottom-up, inorder, recursion
	TreeNode* inorder(int lo, int hi, ListNode* &ref) {
		if (lo > hi) return nullptr;
		int mi = lo + (hi - lo) / 2;
		TreeNode *left = inorder(lo, mi-1, ref);
		TreeNode *root = new TreeNode(ref->val);	// visit
		root->left = left;				// build left
		ref = ref->next;				// forward sorted list
		root->right = inorder(mi+1, hi, ref);		// build right
		return root;
	}
public:
	TreeNode* sortedListToBST1(ListNode* head) {
		// base cases
		if (!head) return nullptr;
		if (!head->next) return new TreeNode(head->val);

		// runner in one step further, walker in start
		ListNode *fast=head->next->next, *slow=head;
		while (fast && fast->next) {
			slow=slow->next;
			fast=fast->next->next;
		}
		TreeNode *root = new TreeNode(slow->next->val);
		root->right = sortedListToBST(slow->next->next);
		//ListNode *save = slow->next;
		slow->next = nullptr;
		root->left = sortedListToBST(head);
		//slow->next = save;
		//cout << root->val << endl;
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		ListNode *p = head;
		int n = 0;
		while (p)
			++n, p = p->next;
		p=head;
		return inorder(0, n-1, p);
	}
	void levelOrder(TreeNode* root) {
		if (!root) return;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {	// nodes per level
				TreeNode *cur=q.front();
				q.pop();
				cout << cur->val << " ";
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			cout << endl;
		}
	}
};

int main() {
	ListNode n0(-10);
	ListNode n1(-3);
	ListNode n2(0);
	ListNode n3(5);
	ListNode n4(9);
	n0.next=&n1, n1.next=&n2, n2.next=&n3, n3.next=&n4;
	Solution s;
	TreeNode *p = s.sortedListToBST1(&n0);
	s.levelOrder(p);
}

