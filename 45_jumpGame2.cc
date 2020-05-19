/* https://leetcode.com/problems/jump-game-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution4 {
public:
  int jump(vector<int>& nums) {
    int n=nums.size(), steps=0;
    if (n<=1) return steps;
    queue<int> q;
    q.push(0);
    while (q.size()) {
      int nn=q.size(); ++steps;
      for (int i=0;i<nn;++i) {
        int cur=q.front();q.pop();
        int reach=cur+nums[cur];
        if (reach>=n-1) return steps;
        for (int j=cur+1;j<=reach;j++)
          q.push(j);
      }
    }
    return 0;
  }
};
class Solution3 {
public:
	int jump(vector<int>& nums) { // O(n) BFS like
    int n=nums.size(), steps=1;
    if (n<2) return 0;
    int curReach=nums[0], maxReach=nums[0];
    for (int i=1; i<=min(n-1, maxReach); ++i) {
      curReach=max(curReach, i+nums[i]);
      if (i==n-1)
          return steps;
      if (i==maxReach)
          maxReach=curReach, ++steps;
    }
    return -1;
  }
};
class Solution2 {
public:
	int jump(vector<int>& nums) {   // BFS: brute-force: 91/92
    int n=nums.size(), steps=0;
    if (n<2) return 0;  // why? because n==1 is no jump
    queue<vector<int>> q;
    unordered_set<int> visit;
    q.push({0, nums[0]});
    visit.insert(0);
    while (q.size()) {
      ++steps;
      int m=q.size();
      for (int i=0; i<m; ++i) {
        auto p = q.front(); q.pop();
        int reach = p[0]+p[1];
        if (reach>=n-1) return steps;
        for (int j=p[0]+1; j<=reach; ++j) {
          if (visit.count(j)==0)
            q.push({j,nums[j]});
            visit.insert(j);
        }
      }
    }
    return -1;
  }
};
class Solution {
public:
	int jump(vector<int>& nums) {
		int i=0, step=0, end=0, n=nums.size(), reach=0;
		while (end < n-1) {	// image go on a tree
			++step;
			for (;i<=end; ++i) {
				reach = std::max(reach, i+nums[i]);
				if (reach >= n-1) return step;
			}
			if (end == reach) break; // stuck at reach
			end = reach;
		}
		return n==1? 0: -1;
	}
};
int main(){
	Solution4 s;
	vector<int> nums1{2,3,1,1,4};
	//cout << s.jump(nums1) << endl;
	vector<int> nums2{1,2,3};
	//cout << s.jump(nums2) << endl;
	vector<int> nums3{0};
	//cout << s.jump(nums3) << endl;
	vector<int> nums4{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
	cout << s.jump(nums4) << endl;
	vector<int> nums5{5,8,1,8,9,8,7,1,7,5,8,6,5,4,7,3,9,9,0,6,6,3,4,8,0,5,8,9,5,3,7,2,1,8,2,3,8,9,4,7,6,2,5,2,8,2,7,9,3,7,6,9,2,0,8,2,7,8,4,4,1,1,6,4,1,0,7,2,0,3,9,8,7,7,0,6,9,9,7,3,6,3,4,8,6,4,3,3,2,7,8,5,8,6,0};
	cout << s.jump(nums5) << endl;
} 
