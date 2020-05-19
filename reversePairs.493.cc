#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int reversePairs(vector<int>& A) { 
    int n=A.size(),res=0;
    for (int i=0;i<n-1;++i) for (int j=i+1;j<n;++j) {
      long ai=A[i],aj=A[j];
      if (ai> aj*2) ++res;
    }
    return res;
  }
};
int main(){

}
