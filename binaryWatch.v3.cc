#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> ans;
		for (int h=0; h<12; ++h) {
			for (int m=0; m<60; ++m) {
				if (bitset<10>(h<<6|m).count() == num)
					ans.push_back(to_string(h) + (m<10? ":0": ":") + to_string(m));

			}
		}
		return ans;
	}
};
int main(){
	Solution s;
	vector<string> ans = s.readBinaryWatch(1);
	for (auto v: ans) cout << v << " ";
	cout << endl;
}
