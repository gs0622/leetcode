#include <bits/stdc++.h>
using namespace std;
class Solution {
  priority_queue<int,vector<int>,less<int>> maxheap;      // smaller half
  priority_queue<int,vector<int>,greater<int>> minheap;   // larger half
  int n;
public:
  void add(int val) {
    ++n;
    if (n==1) {
        maxheap.push(val);
        return;
    }
    if (val>maxheap.top())
      minheap.push(val);
    else
      maxheap.push(val);

    int diff=maxheap.size()-minheap.size();
    if (diff > 1)
        minheap.push(maxheap.top()), maxheap.pop();
    else if (diff < -1)
        maxheap.push(minheap.top()), minheap.pop();
  }
  double median(void) {
    if (n==0) return -1;
    int res;
    if (n%2) {
      res=minheap.size()>maxheap.size()? minheap.top(): maxheap.top();
    } else {
      res=minheap.top() + maxheap.top(), res/=2.0;
    }
    return res;
  }
};
int main(){
  Solution s;

}
