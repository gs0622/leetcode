#include <bits/stdc++.h>
using namespace std;
class Solution {
  unordered_map<int,int> mp{{1,1},{2,4},{3,9},{4,16},{5,25},{6,36},{7,49},{8,64},{9,81}};
public:
  bool isHappy(int n) {
    unordered_set<int> st;
    while (n>1) {
      if (st.count(n))
        return false;
      st.insert(n);
      int v=n,vv=0;
      while (v>0)
        vv+=mp[v%10],v/=10;
      n=vv;
    }
    return n==1;
  }
};
class Solution1 {
public:
  bool isHappy(int n) {
    unordered_set<int> st;
    function<int(int)> helper=[&](int v) {
      int res=0;
      while (v>0) res+=(v%10)*(v%10),v/=10; 
      return res;
    };
    while (n>1) {
      if (st.count(n)) return false;
      st.insert(n);
      n=helper(n);
    }
    return n==1;
  }
};
int main(){
  Solution s;
  cout << s.isHappy(19) << endl;
  cout << s.isHappy(20) << endl;
  cout << s.isHappy(12) << endl;
}
