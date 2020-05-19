#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	char findTheDifference(string s, string t) {
		string st = s+t;
		char xo = 0;
		for (auto c: st) xo ^= c;
		return xo;
	}
	char findTheDifference2(string s, string t) {
		unordered_set<char> us;
		for (auto c: s) us.insert(c);
		for (auto c: t)
			if (us.count(c)==0) return c;
	}
};
int main(){
	Solution so;
	string s{"abcd"}, t{"abcde"};
	cout << so.findTheDifference(s,t) << endl;
}
