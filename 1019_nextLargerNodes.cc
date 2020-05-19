#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  vector<int> nextLargerNodes(ListNode* head) {
    ListNode *p=head;
    int n=0;
    vector<int> v;
    while (p) v.push_back(p->val), ++n, p=p->next;
    vector<int> res(n,0);
    stack<int> stk;
    for (int i=0; i<n; ++i) {
      while (stk.size() && v[stk.top()] < v[i]) {
        res[stk.top()]=v[i], stk.pop();
      }
      stk.push(i);
    }
    return res;
  }
};
int main(){
  Solution s;
}
