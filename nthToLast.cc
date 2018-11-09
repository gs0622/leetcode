#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode (int v): val(v), next(nullptr) {}
	ListNode (int v, ListNode *n): val(v), next(n) {}
};
class Solution {
public:
	ListNode *nthToLast(ListNode *head, int n) {
		ListNode *f = head, *s=head;	// Q: is n always valid?
		for (int i=0; i<n; ++i) {	// Q: start from the last valid node or nullptr?
			assert(f);
			f = f->next;
		}
		//assert(f);
		while (f) {
			f = f->next, s = s->next;
		}
		return s;
	}
};
int main(){
	ListNode n0(0), n1(1, &n0), n2(2,&n1), n3(3,&n2), n4(4,&n3);
	Solution s;
	ListNode *p = s.nthToLast(&n4, 2);
	cout << p->val << endl;
	p = s.nthToLast(&n4, 5);
	cout << p->val << endl;
}
