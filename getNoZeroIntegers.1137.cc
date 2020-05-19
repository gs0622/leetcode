#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i=1;i<n-1;++i) {
      int j=n-i;
      if (to_string(i).find('0')==string::npos && to_string(j).find('0')==string::npos)
        return {i,j};
    }
    return {};
  }
};
int main(){}
