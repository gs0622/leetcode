#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> prisonAfterNDays1(vector<int>& cells, int N) {
		int n=cells.size();
		unordered_map<string,int> mp;
		while (N) {
			vector<int> tmp(n,0);
			string s(cells.begin(), cells.end());
			mp[s]=N--;		// this state
			for (int i=1; i<n-1; ++i)
				tmp[i]=cells[i-1]==cells[i+1]? 1: 0;
			cells.swap(tmp);
			string ss(cells.begin(), cells.end());
			if (mp.count(ss)) {
				N%=mp[ss]-N;
			}
		}
		return cells;
	}
	// Brute-force simulation
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		int n=cells.size();
		while (N--) {
			vector<int> tmp(n,0);
			for (int i=1; i<n-1; ++i)
				tmp[i]=cells[i-1]==cells[i+1]? 1: 0;
			cells.swap(tmp);
		}
		return cells;
	}
};
int main(){
	Solution s;
	vector<int> A1{0,1,0,1,1,0,0,1};
	for (auto n: s.prisonAfterNDays1(A1,7)) cout << n << " ";
	cout << endl;
	vector<int> A2{1,0,0,1,0,0,1,0};
	for (auto n: s.prisonAfterNDays1(A2,1000000000)) cout << n << " ";
	cout << endl;
	vector<int> A3{0,1,1,1,0,0,0,0};
	for (auto n: s.prisonAfterNDays1(A3,99)) cout << n << " ";
	cout << endl;
}
