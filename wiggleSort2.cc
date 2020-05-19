/*
https://leetcode.com/problems/wiggle-sort-ii/description/
all odd indexes are greater than the even indexes.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  void wiggleSort(vector<int>& nums) {
    vector<int> tmp(nums);
    sort(begin(tmp), end(tmp)); //nlogn
    for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; --i)
      nums[i]=tmp[i&1? k++: j++];
  }
};
class Solution {
public:
  void wiggleSort(vector<int>& nums){ // O(n) time, O(1) space
    int n=nums.size();
 
    // get the median, O(n) by select
    nth_element(nums.begin(),nums.begin()+(n|1)/2, nums.end());
    int median=nums[(n|1)/2]; // bias to the right

    // virtual index helper
    auto id=[&](int i){ return (1+(2*i))%(n|1); };

    /*
      S S M M L L
      0 1 2 3 4 5
      M L S L S M
    */
    int lo=0, i=0, hi=n-1;
    while (i<=hi) {
      int j=id(i);
      if (nums[j]>median)
        swap(nums[id(lo++)], nums[id(i++)]);
      else if (nums[j]<median)
        swap(nums[id(hi--)], nums[j]);
      else
        ++i;
    }
  }
};
int main(){
  Solution s;
  vector<int> A1{1,5,1,1,6,4};
  s.wiggleSort(A1);
  for (auto n: A1) cout << n << " ";
  cout << endl;
  vector<int> A2{1,1,2,1,2,2,1};
  s.wiggleSort(A2);
  for (auto n: A2) cout << n << " ";
  cout << endl;
  vector<int> A3{1,3,2,2,3,1};
  s.wiggleSort(A3);
  for (auto n: A3) cout << n << " ";
  cout << endl;
}
