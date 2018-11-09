/**
 * https://leetcode.com/problems/swap-nodes-in-pairs
 *
 * Definition for singly-linked list.
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *y) : val(x), next(y) {}
};

class Solution {
public:
	ListNode* swapPairs2(ListNode* head) {
		ListNode dummy(0, head);
		ListNode *prev = &dummy, *p = head;
		while (p && p->next) {
			ListNode *q = p->next, *r = p->next->next;
			prev->next = q;		// hook to the second
			q->next = p;		// reverse 1/2
			p->next = r;		// reverse 2/2
			prev = p;		// forward 1/2
			p = r;			// forward 2/2
		}
		return dummy.next;
	}
	ListNode* swapPairs1(ListNode* head) {
		ListNode **ref = &head, *a, *b;
		while ((a = *ref) && (b = a->next)) {
			a->next = b->next;
			b->next = a;
			*ref = b;
			ref = &(a->next);
		}
		return head;
	}
	ListNode* swapPairs(ListNode* head) {
		if (!head) return nullptr;
		if (!head->next) return head;
		ListNode *slow, *fast, *next;
		slow = head;
		fast = head->next;
		next = fast->next;
		fast->next = slow;
		slow->next = next;
		if (next) next = swapPairs(next);	// defer
		slow->next = next;
		head = fast;
		return head;
	}
};

int main(void) {
	ListNode n6(6,nullptr), n5(5, &n6), n4(4, &n5), n3(3, &n4), n2(2, &n3), n1(1, &n2), n0(0, &n1);
	ListNode *p = &n0;
	while (p) {cout << p->val << ' ', p=p->next;} cout << endl;
	Solution s;
	p = s.swapPairs2(&n0);
	while (p) {cout << p->val << ' ', p=p->next;} cout << endl;
}
