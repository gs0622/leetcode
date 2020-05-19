#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool checkIfExist(vector<int>& A) {
    unordered_set<int> st;
    for (auto a: A) {
      if (st.count(a*2)) return true; // up
      else if (a%2==0 && st.count(a/2)) return true;  // down
      st.insert(a);
    }
    return false;
  }
};
int main(){
  Solution s;
  vector<int> A1{0,0};
  cout << s.checkIfExist(A1) << endl;
}
