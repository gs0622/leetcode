#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  vector<int> mergeSort(vector<int>& A) {
    int n=A.size(),lo,mi,hi;
    vector<int> aux(n);
    auto merge=[&](int lo, int mi, int hi) {
      for (int i=lo;i<=hi;++i)
        aux[i]=A[i];                        // copy to aux
      for (int i=lo,j=mi+1,k=lo;k<=hi;++k)  // [lo..mi,mi+1...hi] inclusive
        if      (i>mi)          A[k]=aux[j++];
        else if (j>hi)          A[k]=aux[i++];
        else if (aux[j]>aux[i]) A[k]=aux[i++];
        else                    A[k]=aux[j++];
    };
    for (int span=1;span<n;span*=2) {
      for (lo=0;lo<n-1;lo+=span*2) {
        mi=min(lo+span-1,n-1);
        hi=min(lo+span*2-1,n-1);
        merge(lo,mi,hi);
      }
    }
    assert(is_sorted(A.begin(),A.end()));
    return A;
  }
};
class Solution {
public:
  vector<int> mergeSort(vector<int>& A) {
    int n=A.size(), lo=0, hi=n-1;
    vector<int> aux(n);
    auto merge=[&](int lo, int mi, int hi) {
      for (int i=lo;i<=hi;++i)
        aux[i]=A[i];                        // copy to aux
      for (int i=lo,j=mi+1,k=lo;k<=hi;++k)  // [lo..mi,mi+1...hi] inclusive
        if      (i>mi)          A[k]=aux[j++];
        else if (j>hi)          A[k]=aux[i++];
        else if (aux[j]>aux[i]) A[k]=aux[i++];
        else                    A[k]=aux[j++];
    };
    function<void(int,int)> sort=[&](int lo, int hi){
      if (lo>=hi) return;
      int mi=lo+(hi-lo)/2;
      sort(lo,mi);
      sort(mi+1,hi);
      merge(lo,mi,hi);
    };
    sort(lo,hi);
    assert(is_sorted(A.begin(),A.end()));
    return A;
  }
};
int main(){
  Solution s;
  vector<int> A1{9,8,7,6,5,4,3,2,1};
  for (auto n: s.mergeSort(A1)) cout << n << " ";
  cout << endl;
}
