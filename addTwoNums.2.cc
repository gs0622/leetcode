/* https://leetcode.com/problems/add-two-numbers/description/
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* addTwoNumbers1(ListNode* a1, ListNode* a2) {
		ListNode dummy, *tail=&dummy;
		bool carry = false;
		while (a1 || a2 || carry) {
			int x = a1? a1->val: 0;
			int y = a2? a2->val: 0;
			int z = x + y + (carry? 1: 0);
			ListNode *cur = new ListNode(z%10);
			carry = z>9? true: false;
			tail->next = cur, tail = tail->next;
			if (a1) a1 = a1->next;
			if (a2) a2 = a2->next;
		}
		return dummy.next;
	}
	ListNode* addTwoNumbers(ListNode* a1, ListNode* a2) {
		ListNode dummy, *tail = &dummy;
		bool carry = false;
		while (a1 || a2 || carry) {
			ListNode *n = new ListNode();
			int x = a1? a1->val: 0;
			int y = a2? a2->val: 0;
			n->val = x + y + (carry? 1: 0);
			carry = n->val / 10;
			n->val %= 10;
			a1 = a1? a1->next: a1;
			a2 = a2? a2->next: a2;
			tail->next = n;
			tail = tail->next;
		}
		return dummy.next;
	}
};

int main(void) {
	ListNode a0(2), a1(4), a2(3), b0(5), b1(6), b2(4);
	a0.next=&a1, a1.next=&a2, b0.next=&b1, b1.next=&b2;
	Solution s;
	ListNode *p = s.addTwoNumbers1(&a0, &b0);
	while (p) cout << p->val << ' ', p=p->next;
	cout << endl;
	return 0;
}
