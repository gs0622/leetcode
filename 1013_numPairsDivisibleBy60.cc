/* https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
In a list of songs, the i-th song has a duration of time[i] seconds. 

Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
Formally, we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution3 {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
      vector<int> cnt(60);
      int res=0;
      for (auto t: time)
        res+=cnt[(60-t%60)%60],cnt[t%60]+=1;
      return res;
  }
};
class Solution2 {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<int,int> mp;
    int n=time.size(), res=0;
    for (auto i: time) {
      int tar = (60-i%60)%60;
      if (mp.count(tar)) res+=mp[tar];
      ++mp[i%60];
    }
    return res;
  }
};
class Solution {
public:
  // O(n^2)
  int numPairsDivisibleBy60(vector<int>& time) {
    int n=time.size(), res=0;
    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
      if (i==j) continue;
      if ((time[i]+time[j]) % 60 == 0) ++res;
    }
    return res;
  }
};
int main(){
  Solution3 s;
  vector<int> A1{30,20,150,100,40};
  cout << s.numPairsDivisibleBy60(A1) << endl;
  vector<int> A2(60000,60);
  cout << s.numPairsDivisibleBy60(A2) << endl;
}
