#include <bits/stdc++.h>
using namespace std;
class Solution {
	vector<string> pow2;
public:
	Solution(){
		for (int i=0; i<32; ++i) pow2.push_back(to_string(1<<i)), sort(pow2[i].begin(), pow2[i].end());
	}
	bool reorderedPowerOf2(int n) {
		string s = to_string(n);
		sort(s.begin(), s.end());
		for (auto s2: pow2) if (s2==s) return true;
		return false;
	}
};
int main(){
	Solution s;
	cout << s.reorderedPowerOf2(1) << endl;
	cout << s.reorderedPowerOf2(10) << endl;
	cout << s.reorderedPowerOf2(16) << endl;
	cout << s.reorderedPowerOf2(24) << endl;
	cout << s.reorderedPowerOf2(46) << endl;
}
