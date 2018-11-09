/* https://leetcode.com/problems/heaters/description/
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

hint: for every house, find the nearest heater, keep the max dist as min radius
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(begin(houses), end(houses));
		sort(begin(heaters), end(heaters));
		int i=0, res=0;
		for (auto h: houses) { // sort of two pointers
			while (i<heaters.size()-1 && abs(heaters[i]-h) >= abs(heaters[i+1]-h)) ++i;
			res = max(res, abs(heaters[i]-h));	// max for every nearest dist
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> houses1{1,2,3}, heaters1{2};
	cout << s.findRadius(houses1, heaters1) << endl;

	vector<int> houses2{1,2,3,4}, heaters2{1,4};
	cout << s.findRadius(houses2, heaters2) << endl;
}
