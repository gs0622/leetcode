/* https://leetcode.com/problems/top-k-frequent-elements/description/ */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int,int> freq;
		for (auto n: nums) freq[n]++;
		vector<vector<int>> buckets(nums.size()+1, vector<int>());
		for (auto f: freq) buckets[f.second].push_back(f.first);
		vector<int> res;
		for (int i=nums.size(); i>0 & k>0; --i) {
			while (buckets[i].size() > 0) {
				int j = buckets[i].back();
				res.push_back(j);
				buckets[i].pop_back();
				if (--k == 0) break;
			}
		}
		return res;
	}
	vector<int> topKFrequent1(vector<int>& nums, int k) {
		unordered_map<int,int> m;
		for (auto n: nums) m[n]++;
		vector<pair<int,int>> v;
		for (auto x: m) v.push_back(make_pair(x.second, x.first));
		std::sort(v.rbegin(), v.rend());
		vector<int> res;
		for (int i=0; i<k; ++i) res.push_back(v[i].second);
		return res;
	}
	vector<int> topKFrequent2(vector<int>& nums, int k) {
		unordered_map<int,int> m;
		for (auto n: nums) m[n]++;
		priority_queue<pair<int,int>> pq;
		for (auto p: m) // pair of key/count
			pq.push(make_pair(p.second, p.first));
		vector<int> res;
		while (k--) {
			auto p = pq.top();
			res.push_back(p.second);
			pq.pop();
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res, nums{1,1,1,2,2,3};
	res = s.topKFrequent1(nums, 2);
	for (auto n: res) cout << n << " ";
	cout << endl;
	res = s.topKFrequent2(nums, 2);
	for (auto n: res) cout << n << " ";
	cout << endl;
}

