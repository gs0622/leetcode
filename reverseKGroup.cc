#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int v): val(v), next(nullptr) {}
};
class Solution3{
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    int n=0;
    ListNode dummy(0),*cur=head,*pre=&dummy;
    dummy.next=head;
    while (cur) ++n, cur=cur->next;
    cur=head;
    for (int i=0; i<n/k; ++i) {
      for (int j=0;j<k-1;++j) {
        //if (!cur || !cur->next) break;
        auto next=pre->next;        // save
        pre->next=cur->next;        // jump
        cur->next=cur->next->next;  // jump
        pre->next->next=next;
      }
      pre=cur,cur=cur->next;
    }
    return dummy.next;
  }
};
class Solution2{
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0), *pre=&dummy, *cur=head;
    dummy.next=head;
    int i=0;
    stack<ListNode*> stk;
    while (cur) {
      ++i, stk.push(cur), cur=cur->next;
      if (i%k==0)
        while (stk.size())
          pre->next=stk.top(),pre=pre->next,stk.pop();
    }
    if (stk.empty()) pre->next=nullptr;
    else {
      while (stk.size()>1) stk.pop();
      pre->next=stk.top(),pre=pre->next,stk.pop();
    }
    return dummy.next; 
  }
};
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0), *pre=&dummy, *p=head; dummy.next=head;
    stack<ListNode*> stk;
    int i=k;
    while (p) {
      while (i && p) {
        stk.push(p), p=p->next, --i;
      }
      if (i==0) {
        while (stk.size()) {
          pre->next=stk.top();stk.pop();
          pre=pre->next;
        }
        i=k;
        if (!p) pre->next=nullptr;
      } else {
        while (stk.size()>1) stk.pop();
        pre->next=stk.top(); stk.pop();
      }
    }
    return dummy.next;
  }
};
int main(){
  Solution3 s;
  ListNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
  n1.next=&n2,n2.next=&n3,n3.next=&n4,n4.next=&n5,n5.next=&n6;
  //n1.next=&n2;//,n2.next=&n3,n3.next=&n4,n4.next=&n5;
  auto p = s.reverseKGroup(&n1, 5);
  while (p) cout << p->val << " ", p=p->next;
  cout << endl;
}
