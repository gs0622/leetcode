#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {}
};
class Solution {
public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int,ListNode*> mp;  // {val:ptr}
    ListNode dummy(0); dummy.next=head;
    //ListNode *cur=head; // w/o presum 0: output [1,2,1], buggy when input [1,-1]
    ListNode *cur=&dummy; // w/ presum 0: output [3,1], tackle input [1,-1]
    int pre=0;
    while (cur) {
      pre+=cur->val;
      if (mp.count(pre)) { // there is 0 sum sublist
        cur=mp[pre]->next;
        int sum=pre+cur->val;
        while (sum!=pre) {
          mp.erase(sum);
          cur=cur->next;
          sum+=cur->val;
        }
        mp[pre]->next=cur->next;
      } else
        mp[pre]=cur;
      cur=cur->next;
    }
    return dummy.next;
  }
};
int main(){}
