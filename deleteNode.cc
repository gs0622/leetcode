#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* n) : val(x), next(n) {}
};
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode *next = node->next;
		node->val = next->val;
		node->next = next->next;
	}
};
