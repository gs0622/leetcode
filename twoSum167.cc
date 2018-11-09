#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int,int> m;
		for (int i=0; i != numbers.size(); ++i)
			m[numbers[i]] = i;
		vector<int> ans(2,0);
		for (int i=0; i != numbers.size(); ++i) {
			int v = target - numbers[i];
			auto it = m.find(v);
			if (it != m.end()) {
				int first = i, second = it->second;
				if (first > second) std::swap(first, second);
				ans[0] = first+1;
				ans[1] = second+1;
				break;
			}
		}
		return ans;
	}
};
int test1(){
	vector<int> nums{2,7,11,15};
	Solution s;
	vector<int> ans = s.twoSum(nums, 9);
	cout << ans[0] << " " << ans[1] << endl;
}
int test2(){
	vector<int> nums{2,3,4};
	Solution s;
	vector<int> ans = s.twoSum(nums, 6);
	cout << ans[0] << " " << ans[1] << endl;
}
int main(){
	test1();
	test2();
}
