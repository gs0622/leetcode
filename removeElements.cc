/* https://leetcode.com/problems/remove-linked-list-elements/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
	ListNode* removeElements1(ListNode* head, int val) {
		if (!head) return nullptr;
		head->next = removeElements1(head->next, val);
		return head->val!=val? head: head->next;
	}
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(0), *cur = head, *tail = &dummy;
		while (cur) {
			ListNode *next = cur->next;
			if (cur->val != val)
				tail->next = cur, cur->next = nullptr, tail = tail->next;
			cur=next;
		}
		return dummy.next; 
	}
};
int main(){
	ListNode n3(2),n2(1),n1(1,&n2);
	Solution s;
	ListNode *p;
	p = s.removeElements1(&n1,1);
	while (p) cout << p->val << ' ', p=p->next;
	cout << endl;
}
