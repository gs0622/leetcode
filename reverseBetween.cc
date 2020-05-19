/* https://leetcode.com/problems/reverse-linked-list-ii/description/
Reverse a linked list from position m to n. Do it in-place and in one-pass.
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	// O(n) two-pass, stack
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(0), *pre = &dummy;
		dummy.next = head;
		for (int i=0; i<m-1; ++i)	  //pre^      next^ 
			pre = pre->next;		      // 1^ 2 3 4 5
		ListNode *cur = pre->next;	//    2^
		stack<ListNode*> stk;
		for (int i=0; i<n-m; ++i) {
			stk.push(cur);
			cur = cur->next;
		}
		ListNode *next = cur->next;		// save the next
		pre->next = cur;
		while (!stk.empty()) {
			cur->next = stk.top(), stk.pop();
			cur = cur->next;
		}
		cur->next = next;
		return dummy.next;
	}
	ListNode* reverseBetween1(ListNode* head, int m, int n) {
		int i;
		ListNode dummy(0);
		dummy.next = head;
		ListNode *pre = &dummy;
		for (i=0; i<m-1; ++i) pre = pre->next;			// p
		ListNode *start = pre->next;				// q
		ListNode *then = start->next;				// r
		for (i=0; i<n-m; ++i) {
			start->next = then->next; // save then->next	// q->next = r->next
			then->next = pre->next; // start?		// r->next = p->next (q)
			pre->next = then;				// p->next = r
			then = start->next; // then = then->next	// r = q->next (old r->next)
		}
		return dummy.next;
	}
	ListNode* reverseBetween2(ListNode* head, int m, int n) {
		ListNode *cur=head, *s;
		int i;
		vector<int> nums;
		for (i=1; i<=n; ++i) {
			if (i==m) s=cur;
			if (i>=m) nums.push_back(cur->val); 
			cur=cur->next;
		}
		std::reverse(nums.begin(), nums.end());
		for (cur=s, i=0; i<=n-m; ++i) {
			cur->val = nums[i];
			cur=cur->next;
		}
		return head;
	}
};
int main(){
	Solution s;
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5);		// 1->2->3->4->5
	n1.next=&n2, n2.next=&n3, n3.next=&n4, n4.next=&n5;
	s.reverseBetween(&n1, 2, 4);				// 1->4->3->2->5
	ListNode *cur = &n1;
	while (cur) cout << cur->val << " ", cur=cur->next;
	cout << endl;
}
