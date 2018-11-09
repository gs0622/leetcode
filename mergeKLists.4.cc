/* https://leetcode.com/problems/merge-k-sorted-lists/description/
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
	ListNode* merge(ListNode *p, ListNode *q) {
		ListNode dummy(0), *tail = &dummy; // hanger
		while (p && q) {	// both lists require to merge
			if (p->val < q->val)	tail->next = p, p = p->next;
			else			tail->next = q, q = q->next;
			tail = tail->next;
		}
		if (p) tail->next = p;	// p left
		if (q) tail->next = q;	// q left
		return dummy.next;
	}
public:
	// O(nklog(k)) divide and conquer
	ListNode* mergeKLists4(vector<ListNode*>& lists) {
		if (lists.size()==0) return nullptr;
		while (lists.size()>1) {
			lists.push_back(merge(lists[0], lists[1]));
			lists.erase(lists.begin(), lists.begin()+2);
		}
		return lists.front();
	}
	// O(nklog(k)) divide and conquer
	ListNode* mergeKLists3(vector<ListNode*>& lists) {
		if (lists.size() == 0) return nullptr;
		while (lists.size()>1) {
			//ListNode *head = merge(*begin(lists), *(begin(lists)+1));
			//lists.erase(begin(lists),begin(lists)+2); // exclude the last
			ListNode *head = merge(lists.front(), lists.back());
			lists.erase(begin(lists));
			lists.pop_back();
			lists.push_back(head);
		}
		return lists.front();
	}
	// O(nklog(k)) divide and conquer
	ListNode* mergeKLists2(vector<ListNode*>& lists) {
		if (lists.size() == 0) return nullptr;
		ListNode *head = lists.front(), *tail;
		while (lists.size()>1) {
			head = lists.front();
			lists.erase(begin(lists));
			tail = lists.back();
			lists.pop_back();
			head = merge(head, tail);
			lists.push_back(head);
		}
		return head;
	}
	// O(nk^2), k lists
	ListNode* mergeKLists1(vector<ListNode*>& lists) {
		ListNode *p = nullptr;
		for (auto q: lists) p = merge(p, q);
		return p;
	}	
};
int main(){
	Solution s;
	ListNode* a = nullptr;
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	vector<ListNode*> lists{a,b,c,d};
	ListNode* r = s.mergeKLists3(lists);
	while (r) cout << r->val << " ", r = r->next;
	cout << endl;
}
