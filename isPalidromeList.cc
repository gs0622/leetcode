/*
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// does single one count as palindrom?
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode *fast = head, *slow = head;
		stack<int> s;
		int cnt = 0;
		while (fast && fast->next) {
			s.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
			cnt += 1;
		}
		if (fast) slow = slow->next; // odd nums
		while (slow) {
			if (s.top() != slow->val)
				return false;
			s.pop(), slow = slow->next;
		}
		return true;
	}
};
int main(){
	Solution s;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(2);
	ListNode n4(1);
	ListNode n5(1);
	n1.next=&n2, n2.next=&n3, n3.next=&n4, n4.next=&n5;
	cout << s.isPalindrome(&n1) << endl;
}
