/* https://leetcode.com/problems/partition-list/description/
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(nullptr) {}
	ListNode(int v, ListNode* n): val(v), next(n) {}
};
class Solution {
public:
	ListNode* partition1(ListNode* head, int x) {
		ListNode dummy1(0), dummy2(0), *cur = head, *p1 = &dummy1, *p2 = &dummy2;
		while (cur) {			// maintain two queues
			if (cur->val < x)	// hook to dummy1 queue
				p1->next = cur, p1=p1->next;
			else			// hook to dummy2 queue
				p2->next = cur, p2=p2->next;
			cur = cur->next;
		}
		p2->next = nullptr;		// terminate dummy2
		p1->next = dummy2.next;		// concatenate dummy2 to dummy1
		return dummy1.next;
	}
	ListNode* partition(ListNode* head, int x) {
		ListNode dummy(INT_MIN), *cur=head, *pre=&dummy;
		dummy.next = head;
		queue<ListNode*> q;	// use queue to preserve relative order when val >= x
		while (cur) {		// pass 1: seperate <x and push >=x elems into queue
			if (cur->val >= x) {
				q.push(cur);
				pre->next = cur->next, cur = cur->next;
			} else
				pre = cur, cur = cur->next;
		}
		cur = pre;
		while (!q.empty()) {	// pass 2: concatenate queue elems back to list
			cur->next = q.front();
			cur = cur->next;
			q.pop();
		}
		cur->next = nullptr;
		return dummy.next;
	}
};
int main(){
	Solution s;
	// 1->4->3->2->5->2
	ListNode n6(2), n5(5,&n6), n4(2,&n5), n3(3,&n4), n2(4,&n3), n1(1,&n2);
	ListNode *p;
	p = s.partition1(&n1, 3);
	while (p) cout << p->val << ' ', p = p->next;
	cout << endl;
	ListNode m2(2), m1(1,&m2);
	p = s.partition1(&m1, 0);
	while (p) cout << p->val << ' ', p = p->next;
	cout << endl;
}
