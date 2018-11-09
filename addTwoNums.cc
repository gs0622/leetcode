/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a1, ListNode* a2) {
        ListNode dummy, *tail = &dummy;
        bool carry = false;
        while (a1 && a2) {
            ListNode *n = new ListNode;
            tail->next = n;
            n->val = a1->val + a2->val + (carry? 1: 0);
            if (n->val > 9) {
                carry = true;
                n->val %= 10;
            } else
                carry = false;
            a1 = a1->next, a2 = a2->next;
            tail = tail->next;
        }
        while (a1) {
            ListNode *n = new ListNode;
            tail->next = n;
            n->val = a1->val + (carry? 1: 0);
            if (n->val > 9) {
                carry = true;
                n->val %= 10;
            } else
                carry = false;
            a1 = a1->next;
            tail = tail->next;
        }
        while (a2) {
            ListNode *n = new ListNode;
            tail->next = n;
            n->val = a2->val + (carry? 1: 0);
            if (n->val > 9) {
                carry = true;
                n->val %= 10;
            } else
                carry = false;
            a2 = a2->next;
            tail = tail->next;
        }
        if (carry) {
            ListNode *n = new ListNode;
            tail->next = n;
            n->val = 1;
            carry = false;
            tail = tail->next;
        }
        return dummy.next;
    }
};

int main(void) {
    ListNode a1[3], a2[3], *r;
    a1[0].val = 9, a1[0].next = &a1[1];
    a1[1].val = 9, a1[1].next = &a1[2];
    a1[2].val = 9, a1[2].next = nullptr;
    a2[0].val = 1, a2[0].next = nullptr;
    a2[1].val = 6, a2[1].next = &a2[2];
    a2[2].val = 4, a2[2].next = nullptr;
    Solution s;
    r = s.addTwoNumbers(a1, a2);
    while (r) {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;
    return 0;
}
