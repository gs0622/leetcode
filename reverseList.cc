/* source: https://leetcode.com/problems/reverse-linked-list/description/
Reverse a linked list
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	// O(n) time and space
	ListNode* helper(ListNode *cur, ListNode *prev) {
		if (!cur) return prev;		// tricky
		ListNode *next = cur->next;	// save next, defer to next call to reverse
		cur->next = prev;		// reverse
		return helper(next, cur);	// this head has been reverse
	}
public:
	ListNode* reverseList(ListNode* head) {
		return helper(head, NULL);
	}
	ListNode* reverseList1(ListNode* head) {
		ListNode *pre = nullptr, *cur = head;
		while (cur) {
			head = head->next;	// head steps forward
			cur->next = pre;	// reverse cur
			pre = cur;		// tmp steps
			cur = head;		// cur steps
		}
		return pre;
	}
	// O(n) time, O(1) space: pre-cur-next
	ListNode* reverseList2(ListNode* head) {
		ListNode *pre = nullptr, *cur = head;
		while (cur) {
			ListNode *next = cur->next;	// save next
			cur->next = pre;		// reverse cur
			pre = cur;			// step pre
			cur = next;			// step cur
		}
		return pre;				// new head
	}
	// O(2n) time, O(n) space
	ListNode* reverseList3(ListNode* head) {
		stack<int> s;
		ListNode *p=head, *q=head;
		while (p) s.push(p->val), p=p->next;
		while (q) q->val = s.top(), s.pop(), q=q->next;
		return head;
	}
	// O(n) time and space
	ListNode* reverseList4(ListNode* head) {
		stack<ListNode*> s;
		while (head && head->next)
			s.push(head), head=head->next;
		ListNode *newhead = head; // head->next == nullptr
		while (!s.empty())
			head->next = s.top(), head=head->next, s.pop();
		head->next = nullptr;
		return newhead;
	}
	ListNode* reverseList5(ListNode* head) {
		ListNode dummy(0), *tail=&dummy;
		stack<ListNode*> stk;
		while (head)
			stk.push(head), head=head->next;
		while (stk.size())
			tail->next = stk.top(), stk.pop(), tail=tail->next;
		tail->next = nullptr;
		return dummy.next;
	}
};
int main(){
	Solution s;
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
	n1.next=&n2, n2.next=&n3, n3.next=&n4, n4.next=&n5, n5.next=&n6;
	ListNode *p = s.reverseList5(&n1);
	while (p) cout << p->val << " ", p = p->next;
	cout << endl;
}
