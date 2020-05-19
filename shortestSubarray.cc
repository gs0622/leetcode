/* https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/\

Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int shortestSubarray(vector<int>& A, int K) {
    int n=A.size(),res=INT_MAX,sum=0;
    deque<int> dq;
    unordered_map<int,int> mp;
    for (int i=0;i<n;++i) {
      sum+=A[i];
      mp[i]=sum;
      if (sum>=K) res=min(res,i+1);
      while (dq.size()&&sum-mp[dq.front()]>=K)
        res=min(res,i-dq.front()),dq.pop_front();
      while (dq.size()&&sum<=mp[dq.back()])
        dq.pop_back();
      dq.push_back(i);
    }
    return res==INT_MAX? -1: res;
  }
};
class Solution2 {
public:
	// O(nlog(n))?
	int shortestSubarray2(vector<int>& A, int K) {
		int n=A.size(), res=INT_MAX, sum=0;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		for (int i=0; i<n; ++i) {
			sum += A[i];
			if (sum >= K)
				res = min(res, i+1);
			while (pq.size() && sum-pq.top().first>=K) {
				auto p = pq.top(); pq.pop();
				res = min(res, i-p.second);
			}
			pq.push({sum, i});
		}
		return res==INT_MAX? -1: res;
	}
	// O(n)
	int shortestSubarray1(vector<int>& A, int K) {
		int n=A.size(), res=n+1;
		vector<int> preSum(n+1, 0);
		for (int i=1; i<n+1; ++i)
			preSum[i]=preSum[i-1]+A[i-1];
		deque<int> dq;
		for (int i=0; i<n+1; ++i) {
			while (!dq.empty() && preSum[i]-preSum[dq.front()]>=K)
				res=min(res,i-dq.front()), dq.pop_front();
			while (!dq.empty() && preSum[i]<=preSum[dq.back()])
				dq.pop_back();
			dq.push_back(i);
		}
		return res<=n? res: -1;
	}
	// O(n^2) brute-force, TLE
	int shortestSubarray(vector<int>& A, int K) {
		int res=INT_MAX, n=A.size();
		for (int i=0; i<n; ++i) {		// enumerate all subarrays
			int sum = 0;
			for (int j=i; j<n; ++j) {
				sum += A[j];
				if (sum >= K) {
					res = min(res, j-i+1);
					break;
				}
			}
		}
		return res==INT_MAX? -1: res;
	}
};
int main(){
	Solution s;
	vector<int> A1{1};
	cout << s.shortestSubarray(A1,1) << endl;
	vector<int> A2{1,2};
	cout << s.shortestSubarray(A2,4) << endl;
	vector<int> A3{2,-1,2};
	cout << s.shortestSubarray(A3,3) << endl;
	vector<int> A4{75,-32,50,32,97};
	cout << s.shortestSubarray(A4,129) << endl;
	vector<int> A5{-1,-2,-3,2,3,4};
	cout << s.shortestSubarray(A5,5) << endl;
}
