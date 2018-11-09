/*
https://leetcode.com/problems/merge-two-sorted-lists/#/description
*/
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
    struct ListNode *next;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy, *tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        return dummy.next;
    }
};

int main(void) {
    ListNode a[5];
    a[0] = {1, &a[1]};
    a[1] = {2, nullptr};
    a[2] = {3, &a[3]};
    a[3] = {4, &a[4]};
    a[4] = {5, nullptr};
    Solution s;
    ListNode *h = s.mergeTwoLists(&a[0], &a[2]);
    while (h) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
    return 0;
}
