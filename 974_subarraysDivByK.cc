/* https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int subarraysDivByK2(vector<int>& A, int K) {
		unordered_map<int,int> mp{{0,1}};	// mod (remainder),cnt
		int sum=0,res=0;
		for (auto a: A) {
			sum=(sum+a)%K;			// remainder
			if (sum<0) sum+=K;		// make it positive
			res+=mp[sum];			// add existing remainder count
			mp[sum]+=1;			// count this remainder up
		}
		return res;
	}
	int subarraysDivByK1(vector<int>& A, int K) {
		vector<int> cnt(K);
		cnt[0]=1;
		int pre=0,res=0;
		for (auto a: A) {
			pre=(pre+a%K+K)%K;
			res+=cnt[pre]++;
		}
		return res;
	}
	// O(n^2) naive solution
	int subarraysDivByK(vector<int>& A, int K) {
		int n=A.size(), res=0;
		for (int i=0; i<n; ++i) {
			int sum=0;
			for (int j=i; j<n; ++j) {
				sum+=A[j];
				if (sum%K==0) ++res;
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> A1{4,5,0,-2,-3,1};
	cout << s.subarraysDivByK2(A1,5) << endl;
}
