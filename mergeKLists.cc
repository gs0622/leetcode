/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // Brute-force O(nk^2)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        for (auto x: lists)
            head = mergeTwoLists(head, x);
    
        return head;
    }
};

int main(void) {
    Solution s;
    return 0;
}
