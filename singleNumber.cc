/*
https://leetcode.com/problems/single-number
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution3 {
public:
  int singleNumber(vector<int>& nums) {
    int n=nums.size(),lo=0,hi=n-1;
    while (lo<hi) {
      int mi=lo+(hi-lo)/2;
      if (nums[mi]!=nums[mi-1] && nums[mi]!=nums[mi+1]) return nums[mi];
      if (mi%2) {                         // pp s  pp pp pp pp: [mi]==[mi+1] mi==5 %2==1
        if (nums[mi]==nums[mi+1]) hi=mi;  // pp pp pp pp s  pp: [mi]!=[mi+1]
        else lo=mi;                       //        ^
      } else { // %2==0
        if (nums[mi]==nums[mi+1]) lo=mi;  // pp pp pp s  pp: [mi]==[mi+1] mi=4, %2==0
        else hi=mi;                       // pp s  pp pp pp: [mi]
      }
    }
    return nums[lo];
  }
};
class Solution2 {
public:
  int singleNumber(vector<int>& nums) {
    int n=nums.size();
    for (int i=0;i<n;i+=2)
      if (nums[i]!=nums[i+1] || i==n-1)
        return nums[i];
  }
};
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		std::unordered_set<int> s;			// O(n) space
		for (auto& v: nums) {
			if (s.find(v) != s.end()) s.erase(v);	// 2nd appreance
			else s.insert(v);
		}
		return *s.begin();
	}
};

int main(void)
{
	int a[] = {1, 1, 2, 3, 3};
	std::vector<int> v(a, a+5);
	Solution s;
	std::cout << s.singleNumber(v) << endl;
	return 0;
}
