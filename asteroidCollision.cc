/* https://leetcode.com/problems/asteroid-collision/description/
 - at the end, all the negative star has to be on the left, and all the positive star has to be on the right.
 - from the left, a negative star will pass through if no positive star on the left;
 - keep track of all the positive stars moving to the right, the right most one will be the 1st confront the challenge of any future negative star.
 - if it survives, keep going, otherwise, any past positive star will be exposed to the challenge, by being popped out of the stack.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> asteroidCollision(vector<int>& a) {
		vector<int> s; // vector as stack
		for (auto x: a) {
			while (!s.empty() && s.back() > 0 && s.back() < -x)
				s.pop_back();
			if (s.empty() || x > 0 || s.back() < 0)
				s.push_back(x);
			else if (x < 0 && s.back() == -x)
				s.pop_back();
		}
		return s;
	}
	vector<int> asteroidCollision2(vector<int>& a) {
		vector<int> s; // vector as stack
		for (int i=0; i<a.size(); ++i) {
			if (a[i]>0 || s.empty() || s.back()<0) s.push_back(a[i]);
			else if (s.back() <= -a[i]) {
				if (s.back()<-a[i]) --i;
				s.pop_back();
			}
		}
		return s;
	}
};
int main(){
	Solution s;
	vector<int> res;
	vector<int> nums1{5, 10, -5};
	res = s.asteroidCollision(nums1);
	for (auto x: res) cout << x << " ";
	cout << endl;
	vector<int> nums2{8, -8};
	res = s.asteroidCollision(nums2);
	for (auto x: res) cout << x << " ";
	cout << endl;
	vector<int> nums3{10,2,-5};
	res = s.asteroidCollision(nums3);
	for (auto x: res) cout << x << " ";
	cout << endl;
	vector<int> nums4{-2,-1,1,2};
	res = s.asteroidCollision(nums4);
	for (auto x: res) cout << x << " ";
	cout << endl;
	vector<int> nums5{-2,-2,1,-2};
	res = s.asteroidCollision(nums5);
	for (auto x: res) cout << x << " ";
	cout << endl;
}
