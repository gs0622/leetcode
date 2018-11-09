#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n^2), AC, sort by w/h and area, then perform LIS of O(n^2)
	int maxEnvelopes(vector<pair<int,int>>& elps) {
		auto cmp1 = [](pair<int,int> a, pair<int,int> b){
			return (a.first < b.first && a.second < b.second) || (a.first * a.second < b.first * b.second);
		};
		auto cmp2 = [](pair<int,int> a, pair<int,int> b){
			return (a.first < b.first && a.second < b.second);
		};
		sort(begin(elps), end(elps), cmp1);
		vector<int> lis(elps.size(), 1);
		for (int i=1; i<elps.size(); ++i) {
			for (int j=0; j<i; ++j) {
				if (cmp2(elps[j], elps[i])) 
					lis[i]=max(lis[i], lis[j]+1);
			}
		}
		return elps.size()==0? 0: *max_element(begin(lis), end(lis));
	}
	// wrong? another O(nlog(n)) lis approach
	int maxEnvelopes1(vector<pair<int,int>>& elps) {
		auto cmp1 = [](pair<int,int> a, pair<int,int> b){
			return (a.first < b.first && a.second < b.second) || (a.first * a.second < b.first * b.second);
		};
		auto cmp2 = [](pair<int,int> a, pair<int,int> b){return a.first < b.first && a.second < b.second;};
		sort(begin(elps), end(elps), cmp1);
		vector<pair<int,int>> lis;
		for (int i=0; i<elps.size(); ++i) {
			auto it = lower_bound(begin(lis), end(lis), elps[i], cmp2);
			if (it == end(lis)) lis.push_back(elps[i]);	// append
			else *it = elps[i];				// replace
		}
		return lis.size();
	}
};
int main(){
	Solution s;
	vector<pair<int,int>> elps1{{5,4},{6,4},{6,7},{2,3}};
	cout << s.maxEnvelopes1(elps1) << endl;
	vector<pair<int,int>> elps2{{17,15},{17,18},{2,8},{7,2},{17,2},{17,8},{6,15}};
	cout << s.maxEnvelopes1(elps2) << endl;
}
