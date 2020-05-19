/* https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
*/
#include <bits/stdc++.h>
using namespace std;
class Solution7 {
    typedef vector<pair<int, int>> Pii;
    typedef Pii::iterator Pit;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        Pii nums_(n);
        for(int i=0;i<n;++i) nums_[i] = {nums[i], i};
        merge(nums_.begin(), nums_.end(), res);
        return res;
    }
    void merge(Pit begin, Pit end, vector<int>& res){
        if(end - begin <= 1) return;
        Pit mid = begin + (end - begin) / 2;
        merge(begin, mid, res);
        merge(mid, end, res);
        for(auto i = begin; i != mid; ++i){
            auto j=lower_bound(mid,end,*i);
            res[i->second] += j - mid;
        }
        inplace_merge(begin, mid, end);
    }
};
class Solution6 {
      void merge(vector<vector<int>>& A, vector<int>& res, int lo, int hi) {
        if (lo>=hi) return;
        int mi=lo+(hi-lo)/2;
        merge(A,res,lo,mi);
        merge(A,res,mi+1,hi);
        auto cmp=[](vector<int> a, vector<int> b) {return a[0]<b[0];};
        for (int i=mi;i>=lo;--i) {
          auto it=lower_bound(A.begin()+mi+1,A.begin()+hi+1,A[i],cmp);  // larger-or-equal
          int dist=distance(A.begin()+mi+1,it); // smaller than A[i][0]
          if (dist==0) break;
          res[A[i][1]]+=dist;
        }
        inplace_merge(A.begin()+lo,A.begin()+mi+1,A.begin()+hi+1, cmp);
      }
public:
    vector<int> countSmaller(vector<int>& nums) {
      int n=nums.size(), l=0, r=n-1;
      vector<vector<int>> mp;
      for (int i=0;i<n;++i) mp.push_back({nums[i],i});  // augmentation
      vector<int> res(n,0);
      merge(mp,res,0,n-1);
      return res;
    }
};
class Solution5 {
public: // naive O(n^2)
    vector<int> countSmaller(vector<int>& nums) {
      int n=nums.size();
      vector<int> res(n,0);
      for (int i=0;i<n;++i) {
        for (int j=i+1;j<n;++j)
          if (nums[j]<nums[i])
            res[i]++;
      }
      return res;
    }
};
class Solution4 {
    typedef vector<pair<int, int>> Pii;
    typedef Pii::iterator Pit;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        Pii nums_(n);
        for(int i = 0; i < n; ++i)
            nums_[i] = {nums[i], i};
        merge(nums_.begin(), nums_.end(), res);
        return res;
    }
    void merge(Pit begin, Pit end, vector<int>& res){
        if(end - begin <= 1)
            return;
        auto mid = begin + (end - begin) / 2;
        merge(begin, mid, res);
        merge(mid, end, res);
        for(auto i = begin, j = mid; i != mid; ++i){
            while(j != end && i->first > j->first)  // j..j' are all smaller than i
                ++j;
            res[i->second] += j - mid;
        }
        inplace_merge(begin, mid, end);
    }
};
class Solution3 {
public:
  vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,0);
    vector<vector<int>> nums_(n, vector<int>(2,0));
    for (int i=0; i<n; ++i) nums_[i]={nums[i],i};
    function<void(int,int)> merge=[&](int lo, int hi){
        if (lo>=hi) return;
        int mi=lo+(hi-lo)/2;
        merge(lo,mi);
        merge(mi+1,hi);
        for (int i=lo,j=mi+1; i<=mi; ++i) {
          while (j<=hi && nums_[i][0] > nums_[j][0]) ++j;
          res[nums_[i][1]]+=j-(mi+1);
        }
        inplace_merge(nums_.begin()+lo,nums_.begin()+mi+1,nums_.begin()+hi+1,
          [](vector<int> a, vector<int> b){ return a[0]<b[0]; });  // O(n)
    };
    merge(0,n-1);
    return res;
  }
  vector<int> countSmaller1(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,0);
    unordered_map<int,int> mp;
    for (int i=0; i<n; ++i) mp[nums[i]]=i;  // O(n), wrong here, TODO: how to handle dup keys (nums[i])
    function<void(int,int)> merge=[&](int lo, int hi) {
      if (lo>=hi) return;
      int mi=lo+(hi-lo)/2;
      merge(lo,mi);     // O(log(n))
      merge(mi+1,hi);
      // merge: lo...mi,mi+1...hi
      //         i.....,j.......
      for (int i=lo,j=mi+1; i<=mi; ++i) {     // O(n), [lo...mi] first halves
        while (j<=hi && nums[i]>nums[j]) ++j; // O(n), [mi+1..] second halves
        res[mp[nums[i]]]+=j-(mi+1);
      }
      inplace_merge(nums.begin()+lo,nums.begin()+mi+1,nums.begin()+hi+1);  // O(n)
    };
    merge(0,n-1);
    return res;
  }
};
class Solution2 {
public:
  // remain buggy
  vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int> mp;
    for (int i=0; i<n; ++i)
        mp[nums[i]]=i;
    vector<int> res(n,0);
    stable_sort(nums.begin(),nums.end(),[&](int i, int j){
        if (i>j && mp[i]<mp[j]) {
          res[mp[i]]+=1;
          //swap(mp[i],mp[j]);
        } else if (j>i && mp[j]<mp[i]) {
          res[mp[j]]+=1;
          //swap(mp[j],mp[i]);
        }
        return i<j;
    });
    return res;
  }
};
class Solution {
public:
  // O(n^2) brute-force
  vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,0);
    for (int i=0; i<n; ++i) {
      int smaller=0;
      for (int j=i+1; j<n; ++j) {
        if (nums[j]<nums[i])
          res[i]+=1;
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  Solution7 s2;
  vector<int> A1{5,2,6,3,1};  // expect output: [2, 1, 1, 0]
  //vector<int> A1{26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};  // expect output: [2, 1, 1, 0]
  for (auto n: s.countSmaller(A1)) cout << n << " ";
  cout << endl;
  for (auto n: s2.countSmaller(A1)) cout << n << " ";
  cout << endl;
  for (auto n: A1) cout << n << " ";
  cout << endl;
}
