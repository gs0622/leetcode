#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int arrayNesting2(vector<int>& nums) {
		int res = 0;
		vector<vector<int>> tmp;
		for (int i=0; i<nums.size(); ++i) {
			tmp.push_back(vector<int>());
			for (int j=i; nums[j]>=0;) {
				int k = nums[j];	// save
				tmp.back().push_back(k);
				nums[i]=-1;		// visit
				j = k;			// next
			}
			res = max(res, (int)tmp.back().size());
		}
		return res;
	}
	int arrayNesting1(vector<int>& nums) {
		int i, j, cnt, n=nums.size(), ans=0;
		vector<int> visit(n);
		for (i=0; i<n; ++i) {
			if (!visit[i]) {
				j=i, cnt=0;
				while (cnt==0||j!=i) {	// 1st or not circle
					visit[j]=1;
					j=nums[j];
					cnt+=1;
				}
			}
			ans=std::max(ans, cnt);
		}
		return ans;
	}
	int arrayNesting(vector<int>& nums) {
		int i, j, n=nums.size(), ans=0;
		for (i=0; i<n; ++i) {
			int nest=0;
			for (j=i; nums[j]>=0; nest++) {
				int tmp = nums[j];	// save nums[j]
				nums[j]=-1;		// trick as visit
				j = tmp;		// assign
			}
			ans=std::max(ans, nest);
		}
		return ans;
	}
};
int main(){
	Solution s;
	vector<int> nums{5,4,0,3,1,6,2};
	vector<int> cp1(nums), cp2(nums);
	cout << s.arrayNesting1(cp1) << ": " << s.arrayNesting2(cp2) << endl; // cout is LIFO?
	cout << endl;
}
