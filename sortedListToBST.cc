#include <bits/stdc++.h>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v): val(v), next(nullptr) {}
	ListNode(int v, ListNode *n): val(v), next(n) {}
};
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution{
	//ListNode *p;
	// bottom-up, inorder, recursion
	TreeNode* sortedListToBST(int lo, int hi, ListNode* &ref) {
		if (lo > hi) return nullptr;
		int mi = lo + (hi - lo) / 2;
		TreeNode *left = sortedListToBST(lo, mi-1, ref);
		TreeNode *root = new TreeNode(ref->val);		// inorder visit 1/2
		ref = ref->next;					// inorder visit 2/2
		root->left = left;
		root->right = sortedListToBST(mi+1, hi, ref);
		return root;
	}
public:
	TreeNode* sortedListToBST(ListNode* head) {
		ListNode *cur = head;
		int len = 0;
		while (cur) ++len, cur = cur->next;
		return sortedListToBST(0, len-1, head);
	}
};

int main() {
	ListNode n5(5), n4(4, &n5), n3(3, &n4), n2(2, &n3), n1(1,&n2);
	Solution s;
	TreeNode *p = s.sortedListToBST(&n1);
	cout << p->val << endl;
}

