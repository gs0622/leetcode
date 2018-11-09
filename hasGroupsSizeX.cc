#include <bits/stdc++.h>
using namespace std;
class Solution {
	/*greatest common divisor*/
	int gcd(int a, int b)
	{
		if (0==b) return a;
		return gcd(b, a%b);
	}
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int,int> mp;
		for (auto d: deck)
			++mp[d];
		int res = 0;
		for (auto it: mp)
			res = gcd(it.second, res);
		return res>1;
	}
};
int main(){
	Solution s;
	vector<int> D1{1,2,3,4,4,3,2,1,5,6};
	cout << s.hasGroupsSizeX(D1) << endl;
	vector<int> D2{1,1,1,2,2,2,3,3};
	cout << s.hasGroupsSizeX(D2) << endl;
	vector<int> D3{1};
	cout << s.hasGroupsSizeX(D3) << endl;
	vector<int> D4{1,1};
	cout << s.hasGroupsSizeX(D4) << endl;
	vector<int> D5{1,1,2,2,2,2};
	cout << s.hasGroupsSizeX(D5) << endl;
	vector<int> D6{1,1,1,1,2,2,2,2,2,2};
	cout << s.hasGroupsSizeX(D6) << endl;
}
