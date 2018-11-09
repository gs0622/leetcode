/* https://leetcode.com/problems/linked-list-random-node/description/

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	vector<ListNode*> nodes;
public:
	Solution(ListNode* head) {
		while (head)
			nodes.push_back(head), head=head->next;
	}
    
	/** Returns a random node's value. */
	int getRandom() {
		int n=nodes.size();
		return nodes[rand()%n]->val;
	}
};
int main(){}
