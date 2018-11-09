#include <bits/stdc++.h>
//#include <algorithm>
//#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		ListNode dummy(0);
		ListNode *cur = head; // current to be sorted
		while (cur) {
			ListNode *tmp = &dummy;
			while (tmp->next && tmp->next->val < cur->val)	// pass all smaller ones
				tmp = tmp->next;
			// tmp->next->val > cur->val
			ListNode *next = cur->next;	// save
			cur->next = tmp->next;		// insert 1/2
			tmp->next = cur;		// insert 2/2
			cur = next;			// step
		}
		return dummy.next;
	}
	ListNode *insertionSortList3(ListNode *head) {
		ListNode dummy(INT_MIN);		// .next=nullptr initially
		while (head) {				// head as sorted iter (ptr)
			ListNode* it = &dummy;
			while (it->next && it->next->val < head->val) {
				it = it->next;
			}
			ListNode* next = head->next;	// save; trick: the first head will append to dummy
			head->next = it->next;		// insert (swap ptr)
			it->next = head;		// insert (swap ptr)
			head = next;			// step
		}
		return dummy.next;
	}
	ListNode* insertionSortList0(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode *cur = head;
		ListNode *pre = &dummy;
		while (cur) {
			ListNode *tmp = cur->next;
			while (pre->next && pre->next->val < cur->val)
				pre = pre->next;
			cur->next = pre->next;
			pre->next = cur;
			pre = &dummy;
			cur = tmp;
		}
		return dummy.next;
	}
	ListNode* insertionSortList1(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *cur = head->next;
		while (cur) {
			ListNode *next = cur->next;
			ListNode *s = head;
			while (s!=cur) {
				if (cur->val < s->val) swap(cur->val, s->val);
				s=s->next;
			}
			cur = next;
		}
		return head;
	}
	ListNode* insertionSortList2(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *s = head;
		ListNode *c = head->next;
		while (c) {
			ListNode *n = c->next;
			while (c) {
				if (c->val < s->val)
					swap(c->val, s->val);
				c = c->next;
			}
			c = n;
			s = s->next;
		}
		return head;
	}
};
int main(){
	Solution s;
	ListNode n0(3);
	ListNode n1(4);
	ListNode n2(1);
	ListNode n3(0);
	n0.next=&n1, n1.next=&n2, n2.next=&n3;
	ListNode *r = s.insertionSortList(&n0);
	while (r) cout << r->val << " ", r = r->next;
	cout << endl;
}
