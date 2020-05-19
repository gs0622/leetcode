/*https://leetcode.com/problems/linked-list-cycle-ii/description/*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
	// O(n) time, O(n) space
	ListNode *detectCycle3(ListNode *head) {
		unordered_set<ListNode*> st;
		ListNode *cur = head;
		while (cur) {
			if (st.count(cur)) return cur;
			st.insert(cur);
			cur = cur->next;
		}
		return nullptr;
	}
	// O(n) time, O(1) space
	ListNode *detectCycle2(ListNode *head) {
		ListNode *s=head, *f=head;
		while (f && f->next) {
			s=s->next;
			f=f->next->next;
			if (s==f) break;
		}
		if (!f || !f->next) return nullptr;
		for (f=head; s!=f;)
			s=s->next, f=f->next;
		return s;
	}
	ListNode *detectCycle1(ListNode *head) {
		if (!head || !head->next) throw -1;
		ListNode *s=head, *f=head;
		do {
			s=s->next;
			f=f->next->next;
		} while (s!=f && s && f && f->next);
		cout << s->val << endl;
		if (!s || !f || !f->next) return nullptr; // no cycle detected
		for (f=head; s!=f;) { // yes, there is cycle
			s=s->next; // same pace
			f=f->next;
			//if (s==f) break; // s meets f as cycle
		}
		return s;
	}
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) return nullptr;
		ListNode *s=head, *f=head->next;
		while (s!=f && s && f && f->next) {
			s=s->next;
			f=f->next->next;
		}
		if (!s || !f || !f->next) return nullptr; // no cycle detected
		for (f=head, s=s->next; s!=f;) { // yes, there is cycle
			s=s->next; // same pace
			f=f->next;
			//if (s==f) break; // s meets f as cycle
		}
		return s;
	}
};
int main(){
	Solution s;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	n1.next=&n2, n2.next=&n3, n3.next=&n4;
	//n4.next=&n2;
	ListNode n5(5);
	n4.next=&n5;
	n5.next=&n2;
	ListNode *p=s.detectCycle3(&n1);
	if (p) cout << p->val << endl;
}
