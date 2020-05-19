/* https://leetcode.com/problems/split-array-with-same-average/description/
In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)
Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.

Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
Note:

The length of A will be in the range [1, 30].
A[i] will be in the range of [0, 10000].

*/
#include <bits/stdc++.h>
using namespace std;
class Solution4 {
public:
	bool splitArraySameAverage(vector<int>& A) {
    int n=A.size(), Asum=accumulate(A.begin(), A.end(), 0);
    //vector<unordered_set<int>> sums(n/2+1);
    vector<set<int>> sums(n/2+1);
    sums[0].insert(0);  // tricky: this is key, presum?
    for (auto a: A) {
        for (int k=n/2; k>=1; --k) {
          for (auto b: sums[k-1])
            sums[k].insert(b+a);
        }
    }
    for (int k=1; k<=n/2; ++k)
      if (Asum*k%n==0 && sums[k].count(Asum*k/n)!=0)
        return true;
    return false;
  }
};
class Solution3 {
public:
	bool splitArraySameAverage(vector<int>& A) {
    int n=A.size(), Asum=accumulate(A.begin(),A.end(),0);
    unordered_map<int,bool> mp;
    function<bool(int,int,int)> dfs=[&](int T, int k, int i){
      if (k==0) return T==0;
      if (k+i>n) return false;
      return dfs(T-A[i],k-1,i+1) || // pick
            dfs(T,k,i+1);           // not-pick
    };
    for (int k=1; k<=n/2; ++k) {    // candidate: Asum*k%n==0
      if (Asum*k%n==0 && dfs(Asum*k/n, k, 0)) // /n => target B/C sum
        return true;
    }
    return false;
  }
};
class Solution2 {
public:
	bool splitArraySameAverage(vector<int>& A) {
    int n=A.size(), s=accumulate(A.begin(), A.end(), 0);
    function<bool(int,int,int)> helper=[&](int T, int k, int i) {
      if (k==0) return T==0;
      if (k+i>n) return false;
      return helper(T-A[i], k-1, i+1) || helper(T, k, i+1); // pick A[i] or not
    };
    for (int i=1; i<=n/2; ++i)  // count
      if (s*i%n==0 && helper(s*i/n, i, 0))
        return true;
    return false;
  }
};
class Solution {
public:
	bool splitArraySameAverage(vector<int>& A) {
		int n=A.size(), m=n/2, tSum=accumulate(begin(A), end(A), 0);
		// early pruning
		bool ans = false;
		for (int i=1; i<=m && !ans; ++i)
			if (tSum*i%n==0) ans = true;
		if (!ans) return false;
		vector<unordered_set<int>> sums(m+1);
		sums[0].insert(0);
		for (int num: A) {
			for (int i=m; i>=1; --i)
				for (const int t: sums[i-1])
					sums[i].insert(t+num);
		}
		for (int i=1; i<=m; ++i)
			if (tSum*i%n==0 && sums[i].find(tSum*i/n) != sums[i].end())
				return true;
		return false;
	}
};
int main(){
	Solution4 s;
	vector<int> nums{1,2,3,4,5,6,7,8};
	cout << s.splitArraySameAverage(nums) << endl;
  vector<int> A2{60,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
	cout << s.splitArraySameAverage(A2) << endl;
}
