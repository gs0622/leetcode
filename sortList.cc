/* https://leetcode.com/problems/sort-list/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	ListNode* merge(ListNode *a, ListNode *b) {
		ListNode dummy(0);
		ListNode *c = &dummy;
		while (a && b) {
			if (a->val < b->val)	c->next = a, a = a->next;
			else			c->next = b, b = b->next;
			c = c->next;
		}

		if (a) c->next = a;
		if (b) c->next = b;
		return dummy.next;
	}
public:
	ListNode* sortList(ListNode* head) {
		// 1. base case
		if (!head || !head->next) return head;
		// 2. split two halves
		ListNode *fast, *slow, *prev;
		slow = fast = head;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = nullptr; // cut two halves
		// 3. sort two halves
		ListNode *a = sortList(head);
		ListNode *b = sortList(slow);

		// 4. merge two halves
		return merge(a, b);
	}
};
int main(){
	Solution s;
	ListNode n0(0);
	ListNode n1(2);
	ListNode n2(4);
	ListNode n3(1);
	ListNode n4(3);
	ListNode n5(5);
	ListNode *p;
	n0.next=&n1, n1.next=&n2, n2.next=&n3, n3.next=&n4, n4.next=&n5;
	p = &n0;
	while (p) cout << p->val << " ", p = p->next;
	cout << endl;
	p = s.sortList(&n0);
	while (p) cout << p->val << " ", p = p->next;
	cout << endl;
}
