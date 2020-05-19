#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val; struct ListNode* next;
  ListNode(int v): val(v), next(nullptr) {}
};
class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;
    ListNode dummy1(0), dummy2(0), *p = head, *q = p->next;
    dummy1.next = p, dummy2.next = q;

    while (q && q->next)
      p->next = q->next, q->next = q->next->next, p = p->next, q = q->next;

    p->next = dummy2.next;
    return dummy1.next;
  }
};
int main(){}
