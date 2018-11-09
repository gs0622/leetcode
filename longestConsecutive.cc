#include <bits/stdc++.h>
using namespace std;
class Solution {
	class UF {
		unordered_map<int,int> id;
		int find(int p) {	// find root
			while (p!=id[p]) p=id[p];
			return p;
		}
	public:
		UF(vector<int>& nums) {
			for (int i=0; i<nums.size(); ++i) id[nums[i]]=nums[i];
		}
		bool isConnect(int p, int q) {
			return find(p)==find(q);
		}
		void unionTwo(int p, int q) {
			if (isConnect(p,q)) return;
			int rp=find(p), rq=find(q);
			id[rp]=rq;
		}
		int major(void) {
			unordered_map<int,int> s;
			for (auto it=begin(id); it!=end(id); ++it)
				++s[find(it->first)];
			int res=0;
			for (auto it=begin(s); it!=end(s); ++it)
				res=max(it->second, res);
			return res;
		}
	};
public:
	int longestConsecutive2(vector<int>& nums) {
		unordered_set<int> nset(begin(nums),end(nums));
		int res=0;
		for (auto n: nums) {
			if (nset.count(n-1)==0) {	// trick: only start counting in lowest num
				int cur=n, streak=1;
				while (nset.count(cur+1))
					cur++, streak++;
				res=max(res,streak);
			}
		}
		return res;
	}
	// Union-find, TLE
	int longestConsecutive(vector<int>& nums) {
		UF uf(nums);
		unordered_set<int> nset(begin(nums), end(nums));
		for (auto n: nums) {
			if (nset.count(n-1)) uf.unionTwo(n, n-1);
			if (nset.count(n+1)) uf.unionTwo(n, n+1);
		}
		return uf.major();
	}
};
int main(){
	Solution s;
	vector<int> nums{100,4,200,1,3,2};
	cout << s.longestConsecutive(nums) << ' ' << s.longestConsecutive2(nums) << endl;
}
