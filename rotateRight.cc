/* https://leetcode.com/problems/rotate-list/description/
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	ListNode *helper(ListNode *head, ListNode *cur, int k, int& i) {
		if (!cur) return nullptr;
		ListNode *n = helper(head, cur->next, k, i);
		if (i==0) cur->next = head;
		i += 1;
		if (k+1==i) {
			ListNode *newhead = cur->next;
			cur->next = nullptr;
			return newhead;
		}
		return n;
	}
public:
	ListNode* rotateLeft(ListNode* head, int k) {
		if (!head) return head;
		ListNode *f = head, *s, *r;			// f,s for iteration, r for newhead
		int len=0;
		while (f) f=f->next, ++len;
		k%=len;
		if (k==0) return head;
		f = s = head;
		for (int i=0; i<len-k; ++i) f=f->next;		// f steps len-k first
		while (f->next) f=f->next, s=s->next;		// both step to until f hitting end in next
		f->next = head, r = s->next, s->next = nullptr;	// concatenate to old head, generate new head
		return r;
	}
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;
		ListNode *f, *s, *r;
		int len=0;
		s = head;
		while (s) s=s->next, len+=1;			// calculate length of link
		k%=len;
		if (k==0) return head;
		f = s = head;
		for (int i=0; i<k; ++i) f = f->next;		// f: 1->2->
		while (f->next) f = f->next, s = s->next;	// s: 1->2->3, f: 5->nullptr
		f->next = head, r = s->next, s->next = nullptr;	// f: 5->1, s: 3->nullptr, r: 4
		return r;
	}
	ListNode* rotateRight2(ListNode* head, int k) {
		int i=0;
		return helper(head, head, k, i);
	}
};
int test1();
int test2();
int main(){
	test1();
	test2();
}
int test1(){
        Solution s;
        vector<ListNode> n(5, 0);
        for (int i=0; i<n.size()-1; ++i) n[i].val=i+1, n[i].next=&n[i+1];
        n[n.size()-1].val = n.size(), n[n.size()-1].next=nullptr;
        //ListNode *p = s.rotateRight(&n[0], 2);
        ListNode *p = s.rotateLeft(&n[0], 2);
	while (p) cout << p->val << " " , p = p->next;
	cout << endl;
}
int test2(){
        Solution s;
        vector<ListNode> n(5, 0);
        for (int i=0; i<n.size()-1; ++i) n[i].val=i+1, n[i].next=&n[i+1];
        n[n.size()-1].val = n.size(), n[n.size()-1].next=nullptr;
        ListNode *p = s.rotateRight(&n[0], 6);
	while (p) cout << p->val << " " , p = p->next;
	cout << endl;
}
