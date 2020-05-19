#include <bits/stdc++.h>
using namespace std;
class Solution {
  ListNode* middleNode(ListNode* head) {
    ListNode *slow=head, *fast=head;
    while (fast->next && fast->next->next)
      slow=slow->next,fast=fast->next->next;
    return fast->next? slow->next: slow;
  }
};
int main(){}
