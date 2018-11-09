#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int sum, carry=0, i=a.size()-1, j=b.size()-1;
		string s;
		while (i>=0 || j>=0 || carry) {
			sum = (i>=0? a[i--]-'0': 0) + (j>=0? b[j--]-'0': 0) + carry;
			s = to_string(sum%2) + s; // this skips std::reverse(s.begin(), s.end())
			carry=sum>1;
		}
		return s;
	}
};
int main(){
	Solution s;
	cout << s.addBinary("11", "1") << endl;
	cout << s.addBinary("0", "0") << endl;
	cout << s.addBinary("1111", "1111") << endl;
}
