#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<int> numOfBurgers(int T, int C) {
    if (T%2==0 && T-2*C>=0 && 4*C-T>=0)
      return {T/2-C,2*C-T/2};
    return {};
  }
};
int main(){}
