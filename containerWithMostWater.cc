/* https://leetcode.com/problems/container-with-most-water/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxArea1(vector<int>& h) {
		int lo=0, hi=h.size()-1, W=0;
		while (lo<hi) {
			int H=min(h[lo], h[hi]);
			W=max(W, H*(hi-lo));
			while (h[lo]<=H && lo<hi) ++lo;
			while (h[hi]<=H && lo<hi) --hi;
		}
		return W;
	}
	int maxArea(vector<int>& h) {
		int i, j, area, max = 0;
		for (i=0, j=h.size()-1; i<j;) {
			if (h[i] < h[j])
				area = (j-i)*h[i], i++;
			else
				area = (j-i)*h[j], j--;
			max = std::max(max, area);
		}
		return max;
	}
};
int main(){
	Solution s;
	vector<int> nums{1,1};
	cout << s.maxArea(nums) << ": " << s.maxArea1(nums) << endl;
	
}
