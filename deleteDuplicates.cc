/* https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(nullptr) {}
	ListNode(int v, ListNode* n): val(v), next(n) {}
};
class Solution2 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		if (head->val == head->next->val) {
			// fix head ptr
			ListNode *cur = head->next->next;
			while (cur && cur->val == head->val) cur = cur->next;
			return deleteDuplicates(cur);			// until unique node
		} else {
			head->next = deleteDuplicates(head->next);	// unique node, so defer to next
		};
		return head;		// return current
	}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode dummy(0, head), *pre=&dummy, *cur=head, *nxt=cur->next;
		bool hasdup = false;
		while (cur && nxt) {
			while (nxt && cur->val == nxt->val) {
				nxt = nxt->next;
				hasdup = true;
			}
			if (hasdup) pre->next = nxt;
			else pre = cur;
			if (!nxt) break;
			cur = nxt, nxt = nxt->next;
			hasdup = false;	
			
		}
		return dummy.next;
	}
};
int main(){
	ListNode n5(5), n41(4,&n5), n42(4, &n41), n31(3, &n42), n32(3, &n31), n2(2, &n32), n1(1, &n2);
	Solution2 s;
	ListNode *p = s.deleteDuplicates(&n1);
	while (p) cout << p->val << ' ', p = p->next;
	cout << endl; 
}
