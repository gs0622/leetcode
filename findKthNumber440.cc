/* https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
K-th Smallest in Lexicographical Order
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	// https://discuss.leetcode.com/assets/uploads/files/1477293057263-upload-40379731-118a-4753-bed9-1cb372790d4b.png?v=qgb1lp804jg
	// Note: 1 ≤ k ≤ n ≤ 10^9
	int findKthNumber1(int n, int k) {
		function<ll(ll,ll)> gaps = [&](ll p, ll q){
			ll gap=0;
			while (p<=n) gap+=min(n+1, (int)q)-p, p*=10, q*=10;
			return gap;
		};
		int cur=1; k-=1;
		while (k) {
			int s = gaps(cur, cur+1);	// calculate preorder steps per cur/cur+1 for given n
			if (s<=k) cur+=1, k-=s;		// if steps <= k, the answer in next 'level order'
			else cur*=10, k-=1;		// if stesp > k, the answer in down level
		}
		return cur;
	}
	// naive one, TLE when n is getting larger
	int findKthNumber(int n, int k) {
		vector<string> nums(n);
		for (int i=1; i<=n; ++i) nums[i-1]=to_string(i);
		sort(begin(nums), end(nums), [](string a, string b){
			return lexicographical_compare(begin(a), end(a), begin(b), end(b));
		});
		return stoi(nums[k-1]);
	}
};
int main(){
	Solution s;
	int n,k;
	while (cin>>n>>k) {
		cout << s.findKthNumber1(n,k) << endl;
		cout << s.findKthNumber(n,k) << endl;
	}
}
