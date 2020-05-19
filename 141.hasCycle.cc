#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val; struct ListNode* next;
  ListNode(int v): val(v), next(nullptr) {}
};
class Solution {
public:
  bool hasCycle(ListNode* head) {
    ListNode *walker, *runner;
    walker = runner = head;
    while (runner && runner->next && runner->next->next) {
      walker = walker->next;
      runner = runner->next->next;
      if (walker == runner) return true;
    }
    return false;
  }
};
int main(){
  
}
