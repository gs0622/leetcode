/* https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 DP, LCS (Longest Common Substring)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// wrong
        int findLength(vector<int>& nums1, vector<int>& nums2) {
                vector<int> nums(min(nums1.size(), nums2.size()));
                auto it=set_intersection(begin(nums1), end(nums1), begin(nums2), end(nums2), begin(nums));
                nums.resize(distance(begin(nums), it));
                return nums.size();
        }
	// O(m*n) DP, LCS (Longest Common Substring)
	int findLength2(vector<int>& A, vector<int>& B) {
		int M = A.size(), N = B.size(), res = 0, e=0;
		vector<vector<int>> dp(M+1, vector<int>(M+1, 0));
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (A[i-1]==B[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
					//res = max(res, dp[i][j]);
					if (dp[i][j]>res) res=dp[i][j], e=j;
				} else dp[i][j] = 0;
			}
		}
		vector<int> lcs(begin(B)+e-res, begin(B)+e); // the substring
		return res;
	}
	// O(m*n), wrong
	int findLength1(vector<int>& A, vector<int>& B) {
		int maxlen=0, len=0;
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < B.size(); ++j) {
				if (A[i] == B[j]) {
					++i;
					if (i > A.size()) break;
					++len;
					maxlen = std::max(maxlen, len);
				} else
					len = 0;
			}
		}
		return maxlen;
	}
};
int test1(){
	vector<int> A {1,2,3,2,1};
	vector<int> B {3,2,1,4,7};
	Solution s;
	cout << s.findLength(A,B) << ": ";
	cout << s.findLength2(A,B) << endl;
}
int test2(){
	vector<int> A {0,1,1,1,1};
	vector<int> B {1,0,1,0,1};
	Solution s;
	cout << s.findLength(A,B) << ": ";
	cout << s.findLength2(A,B) << endl;
}
int main(){
	test1();
	test2();
}
