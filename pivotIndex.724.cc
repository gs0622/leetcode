#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
  int pivotIndex(vector<int>& nums) {
    int n=nums.size(),L=0,R=accumulate(nums.begin(),nums.end(),0);
    for (int i=0;i<n;++i) {
      R-=nums[i];
      if (L==R) return i;
      L+=nums[i];
    }
    return -1;
  }
};
class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int n=nums.size(),sum=0;
    unordered_map<int,int> mp;    // {idx,sum}
    for (int i=0;i<n;++i)         // O(n) to build presum map
      sum+=nums[i],mp[i]=sum;
    for (int i=0;i<n;++i) {       // O(n) to seek pivot
      if (mp[i-1]==mp[n-1]-mp[i]) // mp[-1]==0, mp[n-1]==0
        return i;
    }
    return -1;
  }
};
int main(){
}
