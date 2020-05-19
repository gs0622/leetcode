#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
    ListNode dummy(0), *pa=a, *pb=b;
    while (pa != pb) {
          pa=pa?pa->next: b;
          pb=pb?pb->next: a;
        }
        return pa;
    }
    return dummy.next; 
  }
};
int main(){}
