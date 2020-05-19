#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int threeSumMulti(vector<int>& A, int target) {
		unordered_map<int,long> mp;
		long res=0;
		for (auto a: A) ++mp[a];
		for (auto it1: mp) {
			for (auto it2: mp) {
				int i=it1.first, j=it2.first, k=target-i-j;
				if (mp.count(k)==0) continue;
				if (i==j && j==k) res+=mp[i]*(mp[i]-1)*(mp[i]-2)/6;
				else if (i==j && j!=k) res+=mp[i]*(mp[i]-1)/2*mp[k];
				else if (i<j && j<k) res+=mp[i]*mp[j]*mp[k];
			}
		}
		return res % int(1e9+7);
	}
};
int main(){
	Solution s;
	vector<int> A1{1,1,2,2,3,3,4,4,5,5};
	cout << s.threeSumMulti(A1, 8) << endl;
}
