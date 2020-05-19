#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val; struct ListNode *next;
  ListNode(int v): val(v), next(nullptr) {}
};
class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    ListNode *cur = root, *pre = nullptr;
    int n=0;
    while (cur) ++n, cur=cur->next;   // O(n) to get list count
    int base=n/k, extra=n%k;
    vector<ListNode*> res(k, nullptr);
    cur = root;
    for (int i=0; i<k && cur; ++i, --extra) {
      res[i] = cur;
      for (int j=0; j<base + (extra>0); ++j) {
        pre = cur, cur = cur->next;
      }
      pre->next = nullptr;
    }
    return res;
  }
};
int main(){
  Solution s;
  ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
  n1.next = &n2, n2.next = &n3, n3.next = &n4;//, n4.next = &n5, n5.next = &n6, n6.next = &n7;
  auto res = s.splitListToParts(&n1, 5);
  for (auto p: res) if (p) cout << p->val << " "; else cout << "null ";
  cout << endl;
}
