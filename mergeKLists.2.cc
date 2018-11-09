/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
        ListNode dummy, *tail = &dummy;
        while (p && q) {
            if (p->val < q->val) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }
        if (!p) tail->next = q;
        if (!q) tail->next = p;
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *tail;
        if (lists.size() == 0) return nullptr;
        cout << lists.size() << endl;
        head = *lists.begin();
        lists.erase(lists.begin());
        tail = mergeKLists(lists);
        head = mergeTwoLists(head, tail);
        return head;
    }
};

int main(void) {
    ListNode a[6] = {};
    for (int i = 0; i < 6; i++) a[i].val = i;
    a[1].next = &a[3]; // 1,3
    a[2].next = &a[4]; // 2,4
    a[0].next = &a[5]; // 0,5
    ListNode *p[3];
    p[0] = &a[1];
    p[1] = &a[2];
    p[2] = &a[0];
    vector<ListNode*> lists(p, p+3);
    Solution s;
    ListNode *head = nullptr;
    head = s.mergeKLists(lists);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
