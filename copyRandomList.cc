/*
https://leetcode.com/problems/copy-list-with-random-pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
	RandomListNode(int x, RandomListNode* n, RandomListNode* r) : label(x), next(n), random(r) {}
};
class Solution {
public:
	// O(n) time, O(n) space
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode* > m;
		RandomListNode dummy(0);
		RandomListNode *p = head, *q = &dummy;		// trick: think why not q = dummy.next? why use q->next?
		while (p) {	// shallow copy label
			q->next = new RandomListNode(p->label);	// q step one further from dummy
			m[p] = q->next;				// key 1/2: record src/clone mapping
			p = p->next, q = q->next;
		}
		p = head, q = &dummy;
		while (p) {	// deep copy random pointer
			q->next->random = m[p->random];		// key 2/2: copy ramdom by p/q map
			p = p->next, q = q->next;
		}
		return dummy.next;
	}
	
	// O(n) time, O(1) space: clone structure, resolve random, split
	RandomListNode *copyRandomList1(RandomListNode *head) {
		RandomListNode *p = head;
		// loop1: clone the structure and insert them alternately
		while (p) {
			RandomListNode *next = p->next;
			RandomListNode *copy = new RandomListNode(p->label);
			p->next = copy;
			copy->next = next;
			p = next;
		}

		// loop2: assign the cloned random instance to the cloned one.
		p = head;
		while (p) { // p->next is the copy node
			p->next->random = (p->random)? p->random->next: nullptr; // tricky: p->random->next is the cloned one
			p = p->next->next;
		}

		// loop3: split lists.
		p = head;
		RandomListNode *clone = p? p->next: nullptr;			// trap: be careful
		while (p) {
			RandomListNode *copy = p->next;
			p->next = copy->next;	// p->next->next
			p = p->next;
			copy->next = p? p->next: nullptr;
		}

		return clone;
    }
};

int main(void) {
	Solution s;
	s.copyRandomList(nullptr);
	return 0;
}
