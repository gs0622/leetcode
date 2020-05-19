/*
/* https://leetcode.com/problems/maximum-frequency-stack/description/

Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
*/
#include <bits/stdc++.h>
using namespace std;
class FreqStack {
  unordered_map<int,int> freq;        // {key: freq}
  unordered_map<int,stack<int>> stk;  // {freq: stack}
  int maxfreq=0;
public:
  void push(int x) {  // O(1)
    maxfreq=max(maxfreq, ++freq[x]);
    stk[freq[x]].push(x);
  }
  int pop() {         // O(1)
    int res=stk[maxfreq].top(); stk[maxfreq].pop();
    //if (stk[maxfreq].empty()) maxfreq--;  // wrong, why? check maxfreq=max(maxfreq, ++freq[x]);, this does not update freq table
    if (stk[freq[res]--].empty()) maxfreq--;
    return res;
  }
};

int main(){
  FreqStack stk;
  stk.push(4);
  stk.push(0);
  stk.push(9);
  stk.push(3);
  stk.push(4);
  stk.push(2);
  cout << stk.pop() << endl;
  stk.push(6);
  cout << stk.pop() << endl;
  stk.push(1);
  cout << stk.pop() << endl;
  stk.push(4);
  cout << stk.pop() << endl;
  cout << stk.pop() << endl;
  cout << stk.pop() << endl;
  cout << stk.pop() << endl;
  cout << stk.pop() << endl;
}
