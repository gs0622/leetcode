#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
    int lo=0, hi=A.size()-1;
    while (lo<hi) {
      int mi=lo+(hi-lo)/2;
      if (A[mi]>A[mi+1]) hi=mi;
      else lo=mi+1;
    }
    return lo;
  }
};
int main(){
}
