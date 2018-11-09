#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
		int start(0),total(0),tank(0);
		for (int i=0; i<gas.size(); ++i) {
			tank+=gas[i]-cost[i];
			if (tank<0) {
				start=i+1;
				total+=tank;
				tank=0;
			}
		}
		return (total+tank<0)? -1: start;
	}
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n=gas.size();
		for (int i=0; i<n; ++i) {
			if (gas[i]<cost[i]) continue;
			int tank=gas[i];
			for (int j=(i+1)%n; ;(++j), j%=n) {
				tank-=cost[(j+n-1)%n];
				if (tank < 0)
					break;
				if (j==i)
					return i;
				tank+=gas[j];
			}
		}
		return -1;
	}
};
int main(){
	vector<int> gas1{1,2,3,4,5}, cost1{3,4,5,1,2};
	vector<int> gas2{2,3,4}, cost2{3,4,3};
	Solution s;
	cout << s.canCompleteCircuit1(gas1, cost1) << endl; 
	cout << s.canCompleteCircuit1(gas2, cost2) << endl; 
}
