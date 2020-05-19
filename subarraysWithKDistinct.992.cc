/* https://leetcode.com/problems/subarrays-with-k-different-integers/description/
Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.
(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
Return the number of good subarrays of A.

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int subarraysWithKDistinct(vector<int>& A, int K) {
    int n=A.size(), res=0, cnt=0, rep=0;
    unordered_map<int,int> mp;
    for (int i=0,j=0;i<n;++i) {
      if (mp[A[i]]==0) ++cnt;
      ++mp[A[i]];
      if (cnt>K)
        --mp[A[j]],++j,--cnt,rep=0;
      while (j<i && mp[A[j]]>1)
        --mp[A[j]],++rep,++j;
      if (cnt==K)
        res+=rep+1;
    }
    return res;
  }
};
class Solution2 {
public:
	int subarraysWithKDistinct2(vector<int>& A, int K) {
		int n=A.size();
		function<int(int)> helper=[&](int k) {
			unordered_map<int,int> mp;
			int i=0, res=0;
			for (int j=0; j<n; ++j) {
				if (mp[A[j]]++ == 0) k--;
				while (k<0) {
					if (--mp[A[i]]==0) k++;
					++i;
				}
				res+=j-i+1;
			}
			return res;
		};
		int res = helper(K) - helper(K-1);
		return res;
	}
	int subarraysWithKDistinct1(vector<int>& A, int K) {
		int n=A.size(), cnt=0, rep=0, res=0;
		unordered_map<int,int> mp;
		for (int i=0,j=0; i<n; ++i) {		// i: right of the window, j: left
			if (mp[A[i]]++==0)			      // first see adding unique cnt
				++cnt;
			if (cnt>K)				            // new mp[A[i]]==0, reset rep
				--mp[A[j++]], --cnt, rep=0;
			while (j<i && mp[A[j]]>1)		  // shrink the window by j++, maintain same unique <= K, defer to rep, cover line above
				++rep, --mp[A[j++]];
			if (cnt==K)				            // calculate valid sub arrays when it satisfy to K unique
				res+=rep+1;
		}
		return res;
	}
	// O(n^2) naive brute-force to enumerate all sub arrays
	int subarraysWithKDistinct(vector<int>& A, int K) {
		int n=A.size(), res=0;
		for (int i=0; i<n; ++i) {
			unordered_set<int> st;
			for (int j=i; j<n; ++j) {
				st.insert(A[j]);
				if (st.size()==K)
					++res;
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	Solution2 s2;
	vector<int> A1{1,2,1,2,3};
	cout << s.subarraysWithKDistinct(A1,2) << endl;
	cout << s2.subarraysWithKDistinct1(A1,2) << endl;
	vector<int> A2{1,2,1,3,4};
	cout << s.subarraysWithKDistinct(A2,3) << endl;
	cout << s2.subarraysWithKDistinct1(A2,3) << endl;
}
