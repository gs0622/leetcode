#include <bits/stdc++.h>
using namespace std;
class Solution {
	unordered_map<char,char> mp{{'6','9'},{'9','6'},{'0','0'},{'1','1'},{'8','8'}};
public:
	bool isStrobogrammatic(string num) {
		for (auto it1=num.begin(), it2=num.end()-1; it1<=it2; ++it1, --it2) {	// trick: <=
			if (!mp.count(*it1) || !mp.count(*it2) || mp[*it1]!=*it2)	// tricky: 3 satisfaction
				return false;
		}
		return true;
	}
};
int main(){
	Solution s;
	cout << s.isStrobogrammatic("69") << endl;
	cout << s.isStrobogrammatic("88") << endl;
	cout << s.isStrobogrammatic("818") << endl;
	cout << s.isStrobogrammatic("817") << endl;
	cout << s.isStrobogrammatic("828") << endl;
	cout << s.isStrobogrammatic("8228") << endl;
}
