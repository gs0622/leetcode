/* https://leetcode.com/discuss/interview-question/352458/

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> stringCompare(vector<string>& A, vector<string>& B) {
    int m=A.size(),n=B.size(),freqs[11]={};
    for (auto s: A) { // O(m)
      int cnt[26]={}, mi=INT_MAX;
      for (auto c: s) // update counter, track min index
        cnt[c-'a']++, mi=min(mi,c-'a');
      freqs[cnt[mi]]++; // freq of the min ch
    }

    for (int i=1;i<11;++i)  // build presum
      freqs[i]+=freqs[i-1];

    vector<int> res(n);
    for (int i=0;i<n;++i) { // O(n)
      int cnt[26]={}, mi=INT_MAX;
      for (auto c: B[i])    // update counter, track min index
        cnt[c-'a']++, mi=min(mi,c-'a');
      int freq=cnt[mi];     // query the presum of min index
      res[i]=freq>=1? freqs[freq-1]: 0;
    }
    return res;
  }
};
class Solution1 {
public:
  vector<int> stringCompare(vector<string>& A, vector<string>& B) {
    int m=A.size(), n=B.size();
    vector<int> orderA(m), orderB(n);
    for (int i=0;i<m;++i) { // O(m)
      sort(A[i].begin(),A[i].end());
      orderA[i]=count(A[i].begin(),A[i].end(),A[i][0]);
    }
    for (int i=0;i<n;++i) { // O(n)
      sort(B[i].begin(),B[i].end());
      orderB[i]=count(B[i].begin(),B[i].end(),B[i][0]);
    }
    vector<int> res(n);
    for (int i=0;i<n;++i) {
      int cnt=0;
      for (int j=0;j<m;++j)
        if (orderA[j]<orderB[i]) ++cnt;
      res[i]=cnt;
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<string> A1{"abcd","aabc","bd"}, B1{"aaa","aa"};
  for (auto n: s.stringCompare(A1,B1)) cout << n << " ";
  cout << endl;
}
