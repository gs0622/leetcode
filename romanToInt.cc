#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// Q: How about invalid roman? e.g., VL, IVI ...etc
class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> R{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
		int sum = R[s.back()];
		for (int i=s.size()-2; i>=0; --i) {
			if (R[s[i]] < R[s[i+1]])
				sum -= R[s[i]];
			else
				sum += R[s[i]];
		}
		return sum;
	}
};
int main(){
	Solution s;
	cout << s.romanToInt("MMMCMXCIX") << endl;
}
