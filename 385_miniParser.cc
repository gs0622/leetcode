/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:
String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
*/
#include <bits/stdc++.h>
using namespace std;
/**
 * // This is the interface that allows for creating nested lists.
 */
class NestedInteger {
   public:
     // Constructor initializes an empty nested list.
     NestedInteger();
     // Constructor initializes a single integer.
     NestedInteger(int value);
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;
     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;
     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);
     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);
     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  // If encounters '[', push current NestedInteger to stack and start a new one.
  // If encounters ']', end current NestedInteger and pop a NestedInteger from stack to continue.
  // If encounters ',', append a new number to curr NestedInteger, if this comma is not right after a brackets.
  NestedInteger deserialize(string s) {
    stack<NestedInteger> stk;
    int i=0,j,n=s.size();
    if (s[i]!='[')
      return NestedInteger(atoi(s.c_str()));

    NestedInteger *p = nullptr;
    for (j=0; j<n; ++j) {
      int ch = s[j];
      if (ch=='[') {
        if (p) stk.push((*p);
        p = new NestedInteger();      // start a new one
        i=j+1;
      } else if (ch==']') {
        string ss=s.substr(i,j-i);
        if (ss.size())
          p->add(atoi(ss.c_str()));   // valid, end current one
        if (stk.size()) {
          NestedInteger top = stk.top(); stk.pop();
          top.add(*p);
          p = &top;
        }
        i=j+1;
      } else if (ch==',') {
        p->add(NestedInteger(atoi(s.substr(i,j-i).c_str())));
        i=j+1;
      }
      // think about the else
    }
    return *p;
  }
} ;
class Solution {
public:
  NestedInteger deserialize(string s) {
    istringstream iss(s);
    function<NestedInteger(void)> helper=[&](){
      int num;
      if (iss >> num)
        return NestedInteger(num);
      iss.clear();        // clear error flags
      iss.get();          // pop '['
      NestedInteger res;  // empty list
      while (iss.peek()!=']') {
        res.add(helper());// nested list; defer
        if (iss.peek()==',')
          iss.get();      // pop ','
        //iss.get();      // wrong: flattern?
      }
      iss.get();          // pop '['
      return res;
    };
    return helper();
  }
};

int main(){
  Solution2 s;
  string S1;
}
