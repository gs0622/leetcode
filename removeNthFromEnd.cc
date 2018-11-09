/* https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *n) : val(x), next(n) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd1(ListNode* head, int n) {		// Q: what if invalid n?
		ListNode dummy(0, head), *f = &dummy, *s = &dummy;
		for (int i=0; i<n && f; ++i) f = f->next;		// n steps forward, e.g. f could step to nullptr
		while (f && f->next) s = s->next, f = f->next;		// s follows
		s->next = s->next->next;				// remove
		return dummy.next;
	}
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummy(0), *p = head;
		dummy.next = head;
		int len = 0;
		while (p) {	// calculate len
			p = p->next, len += 1;
		}
		p = &dummy;
		len -= n;
		while (len > 0) {
			p = p->next, len -= 1;
		}
		p->next = p->next->next;
		return dummy.next;
	}
};

int main() {
	ListNode n5(5), n4(4, &n5), n3(3, &n4), n2(2, &n3), n1(1, &n2);
	Solution s;
	ListNode *p = s.removeNthFromEnd1(&n1, 2);
	while (p) cout << p->val << ' ', p = p->next;
	cout << endl;
	ListNode m1(1);
	p = s.removeNthFromEnd1(&m1, 1);
	while (p) cout << p->val << ' ', p = p->next;
	cout << endl;
}
