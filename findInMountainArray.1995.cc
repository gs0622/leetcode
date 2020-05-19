#include <bits/stdc++.h>
using namespace std;
class MountainArray {
public:
int get(int index);
int length();
};
class Solution {
public:
  int findInMountainArray(int target, MountainArray &A) {
    int n=A.length(),lo=0,hi=n-1,peak;
    while (lo<hi) {
      int mi=lo+(hi-lo)/2;
      if (A.get(mi)<A.get(mi+1)) lo=mi+1; // accending
      else hi=mi;
    }
    peak=lo;
    lo=0,hi=peak;
    while (lo<=hi) {    // accending half
      int mi=lo+(hi-lo)/2, val=A.get(mi);
      if (val==target) return mi;
      else if (val<target) lo=mi+1;
      else hi=mi-1;
    }
    lo=peak,hi=n-1;
    while (lo<=hi) {    // decending half
      int mi=lo+(hi-lo)/2, val=A.get(mi);
      if (val==target) return mi;
      else if (val>target) lo=mi+1;
      else hi=mi-1;
    }
    return -1;
  }
};
class Solution2 {
public:
  int findInMountainArray(int target, MountainArray &A) { // O(n) brute-force: too many call
    int n=A.length();
    for (int i=0;i<n;++i) {
      if (A.get(i)==target) return i;
    }
    return -1;
  }
};
int main(){}
