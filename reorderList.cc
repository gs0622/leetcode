struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *p, *q;
        p = head, q = p->next;
        // find middle of the list
        while (q && q->next) {
            p = p->next;
            q = p->next->next;
        }
        // reverse the 2nd half
        ListNode *h2 = p->next;
        p->next = nullptr;
        q = h2->next;
        h2->next = nullptr;
        while (q) {
            p = q->next;
            q->next = h2;
            h2 = q;
            q = p;
        }
        // merge two halves
        ListNode *tmp;
        p = head, q = h2;
        while (p) {
            tmp = p->next;
            p = p->next = q;
            q = tmp;
        }
    }
};

int main() { return 0; }
