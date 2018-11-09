#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode (int v): val(v), next(nullptr) {}
};
class Solution {
public:
	ListNode* addTwoNumbers1(ListNode* a1, ListNode* a2) {
		stack<int> s1, s2;
		while (a1) s1.push(a1->val), a1=a1->next;
		while (a2) s2.push(a2->val), a2=a2->next;
		ListNode *cur = new ListNode(0);
		while (!s1.empty() || !s2.empty()) {
			if (!s1.empty()) cur->val += s1.top(), s1.pop();
			if (!s2.empty()) cur->val += s2.top(), s2.pop();
			ListNode *next = new ListNode(cur->val/10); cur->val %= 10;
			next->next = cur, cur = next;
		}
		return (cur->val>0)? cur: cur->next;
	}
	ListNode* addTwoNumbers(ListNode* a1, ListNode* a2) {
		stack<int> s1, s2;
		while (a1) s1.push(a1->val), a1=a1->next;
		while (a2) s2.push(a2->val), a2=a2->next;
		bool carry=false;
		ListNode dummy(0), *tail=&dummy;
		while (!s1.empty() || !s2.empty() || carry) {
			int x=0,y=0,z;
			if (!s1.empty()) x=s1.top(), s1.pop();
			if (!s2.empty()) y=s2.top(), s2.pop();
			z = x + y + (carry? 1:0);
			ListNode *cur = new ListNode(z%10);
			carry = z>9? 1: 0;
			tail->next = cur;
			tail = tail->next;
		}
		ListNode *pre = nullptr, *cur = dummy.next;
		while (cur) {
			ListNode *next = cur->next;	// save next
			cur->next = pre;		// reverse cur
			pre = cur;			// forward pre
			cur = next;			// forward next
		}
		return pre;
	}
};
int main(){
	ListNode a0(7), a1(2), a2(4), a3(3), b0(5), b1(6), b2(4);
	a0.next=&a1, a1.next=&a2, a2.next=&a3, b0.next=&b1, b1.next=&b2;
	Solution s;
	ListNode *p = s.addTwoNumbers1(&a0, &b0);
	while (p) cout << p->val << ' ', p=p->next;
	cout << endl;
}
