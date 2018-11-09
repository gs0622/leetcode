/*https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/#_=_*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	ListNode* helper(ListNode* head, int n, int& i) {
		if (!head)
			return nullptr;
		ListNode* p = helper(head->next, n, i);
		i+=1;
		if (i==n) {
			// FIXME: the tail one of the list
			ListNode *next = head->next;
			head->val = next->val;
			head->next= next->next;
			return head;
		}
		return p;
	}
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *f, *s, *p;
		s = f = head;
		for (int i=0; i<n; ++i) f = f->next;
		while (f) {
			p = s, s = s->next, f = f->next;
		}
		p->next = s->next;
		return s;
	}
	ListNode* removeNthFromEnd1(ListNode* head, int n) {
		ListNode dummy(0), *f = &dummy, *s=&dummy;	// one step before, as prev
		dummy.next = head;
		for (int i=0; i<n; ++i)
			assert(f), f = f->next;
		while (f->next)					// tricky: s would be prev then
			f = f->next, s = s->next;

		s->next = s->next->next;
		return dummy.next;	// cover n = list size

	}
	ListNode* removeNthFromEnd2(ListNode* head, int n) {
		int i=0;
		return helper(head, n, i);
	}
};

int main() {
	Solution s;
	vector<ListNode> n(10, 0);
	for (int i=0; i<n.size()-1; ++i) n[i].val=i, n[i].next=&n[i+1];
	n[n.size()-1].val = n.size()-1, n[n.size()-1].next=nullptr;
	ListNode *p = s.removeNthFromEnd1(&n[0], 7);
	while (p) cout << p->val << ' ', p = p->next;
	cout << endl;
}
