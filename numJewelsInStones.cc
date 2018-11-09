#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_set<char> s;
		for (auto c: J) s.insert(c);
		int cnt=0;
		for (auto c: S) cnt+=s.count(c);
		return cnt;
	}
};
int main(){
	Solution s;
	cout << s.numJewelsInStones("aA", "aAAbbbb") << endl;
	cout << s.numJewelsInStones("z", "ZZ") << endl;
}
