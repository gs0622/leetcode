#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
/*
      2   4   6
   +------------
 1 |  3   5   7
 7 |  9  11  13
11 | 13  15  17
*/
	// O(klog(k))
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		if (nums1.empty() || nums2.empty() || k==0) return {};
		struct mygreater {
			bool operator()(tuple<int,int,int>& a, tuple<int,int,int>& b) {
				return get<0>(a)+get<1>(a) > get<0>(b)+get<1>(b); // compare the sums of nums1 + nums2
			}
		};
		priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, mygreater > pq;
		for (int i=0; i<min((int)nums1.size(), k); ++i)
			pq.push(make_tuple(nums1[i], nums2[0], 0));  // 0 for j below

		vector<pair<int,int>> res;
		int cnt=k;
		while (cnt-- && !pq.empty()) {
			tuple<int,int,int> top = pq.top();
			pq.pop();
			res.push_back(make_pair(get<0>(top), get<1>(top)));
			int j = get<2>(top);
			if (j<nums2.size()-1) // space to +1
				pq.push(make_tuple(get<0>(top), nums2[j+1], j+1)); // let pq decide next top
		}
		return res;
	}

	// O(mn) brute force
	vector<pair<int, int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int,int>> res;
		for (int i=0; i<nums1.size(); ++i)
			for (int j=0; j<nums2.size(); ++j)
				res.push_back(make_pair(nums1[i], nums2[j]));
		sort(begin(res), end(res), [&](pair<int,int> a, pair<int,int> b){ return a.first+a.second < b.first+b.second;});
		if (k<res.size()) res.resize(k);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums1{1,7,11}, nums2{2,4,6};
	vector<pair<int,int>> res;
	res = s.kSmallestPairs(nums1, nums2, 3);
	for (auto p: res) cout << p.first << "," << p.second << " ";
	cout << endl;

	vector<int> nums3{1,1,2}, nums4{1,2,3};
	res = s.kSmallestPairs(nums3, nums4, 10);
	for (auto p: res) cout << p.first << "," << p.second << " ";
	cout << endl;

	vector<int> nums5{1,2}, nums6{3};
	res = s.kSmallestPairs(nums5, nums6, 3);	// Q: how about k > enumeration pairs
	for (auto p: res) cout << p.first << "," << p.second << " ";
	cout << endl;
}
