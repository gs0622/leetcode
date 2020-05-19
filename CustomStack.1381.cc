#include <bits/stdc++.h>
using namespace std;
class Solution {};
class CustomStack {
  int mx;
  vector<int> data,lazy;
public:
  CustomStack(int maxSize) {
    mx=maxSize;
  }
  void push(int x) {
    if (data.size()>=mx) return;
    data.push_back(x);
    lazy.push_back(0);
  }
  int pop() {
    if (data.empty()) return -1;
    int top=data.size()-1;              // stack top
    if (top>0) lazy[top-1]+=lazy[top];  // lazy add
    int res=data[top]+lazy[top];
    data.pop_back(),lazy.pop_back();
    return res;
  }
  void increment(int k, int val) {
    int top=min((int)data.size(),k)-1;
    if (top>=0) lazy[top]+=val;
  }
};
class CustomStack1 {
  int mx;
  vector<int> data;
public:
  CustomStack1(int maxSize) {
    mx=maxSize;
  }
  void push(int x) {
    if (data.size()>=mx) return;
    data.push_back(x);
  }
  int pop() {
    if (data.empty()) return -1;
    int v=data.back(); data.pop_back();
    return v;
  }
  void increment(int k, int val) {
    int n=data.size();
    for (int i=0;i<min(n,k);++i)
      data[i]+=val;
  }
};
int main(){
CustomStack customStack(3); // Stack is Empty []
customStack.push(1);                          // stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
cout << customStack.pop() << endl;                         // return 2 --> Return top of the stack 2, stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.push(3);                          // stack becomes [1, 2, 3]
customStack.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
customStack.increment(5, 100);                // stack becomes [101, 102, 103]
customStack.increment(2, 100);                // stack becomes [201, 202, 103]
cout << customStack.pop() << endl;                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
cout << customStack.pop() << endl;                            // return 202 --> Return top of the stack 102, stack becomes [201]
cout << customStack.pop() << endl;                            // return 201 --> Return top of the stack 101, stack becomes []
cout << customStack.pop() << endl;                            // return -1 --> Stack is empty return -1.
}
