#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string toHex(int num) {
	if (num==0) return "0";
	const string code = {"0123456789abcdef"};
	string ans;
	int i, j;
	for (i=0; i<8 && num; ++i) { // auto skip heading '0' by if (num != 0)
		ans = code[num & 0xf] + ans;
		num>>=4;
	}
	ans +='\0';
	return ans;
    }
};
int main(){
	Solution s;
	vector<int> nums{26,-1, 0};
	for (auto v: nums) cout << s.toHex(v) << endl;
}
