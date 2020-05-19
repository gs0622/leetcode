/* https://leetcode.com/problems/top-k-frequent-elements/description/ */
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
	// O(nlogK), top K in accending because of minheap attribute
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int,int> mp;      // {key: cnt}
		for (auto n: nums) ++mp[n];     // O(n)

		priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;	// minheap, smaller one gets priority
		for (auto p: mp) {		          // O(n) loop, total O(nlogk)
			pq.push({p.second,p.first});	// cnt, val minheap
			if (pq.size()>k)		          // this makes the heap in logK
				pq.pop();		                // pop smallest freq
		}

		vector<int> res;
		while (pq.size())
			res.push_back(pq.top()[1]), pq.pop();
		return res;
	}
};
class Solution {
public:
	// O(n) time and space: use space to archive the time
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int,int> freq;
		for (auto n: nums) freq[n]++;	// O(n)
		vector<vector<int>> buckets(nums.size()+1, vector<int>()); // keypoint of O(n) approach: 0 to n (n+1), waist O(n) space, worse case assume every elem in freq 1
		for (auto f: freq) buckets[f.second].push_back(f.first);
		vector<int> res;
		for (int i=nums.size(); i>0 & k>0; --i) {		// backward start from the highest bucket
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
		for (auto n: nums) m[n]++;			// O(n), val,count
		priority_queue<pair<int,int>> pq;
		for (auto p: m) // pair of key/count
			pq.push(make_pair(p.second, p.first));	// O(nlog(n)), count,val
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
	Solution2 s2;
	vector<int> res, nums{1,1,1,2,2,3};
	res = s2.topKFrequent(nums, 2);
	for (auto n: res) cout << n << " ";
	cout << endl;
	res = s.topKFrequent2(nums, 2);
	for (auto n: res) cout << n << " ";
	cout << endl;
}

