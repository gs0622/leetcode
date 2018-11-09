/* https://leetcode.com/problems/multiply-strings/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string multiply(string a, string b) {
		int i, j, mul, carry, m=a.size(), n=b.size();
		string s(m+n, '0');
		for (i=m-1; i>=0; --i) {
			carry=0;
			for (j=n-1; j>=0; --j) {
				mul=(s[i+j+1]-'0')+(a[i]-'0')*(b[j]-'0')+carry;
				s[i+j+1]=mul%10+'0';
				carry = mul/10;
			}
			s[i]+=carry;
		}
		int pos=s.find_first_not_of('0');
		return (pos==string::npos)? "0": s.substr(pos);
	}
};
int main(){
	Solution s;
	cout << s.multiply("0","0") << endl;
	cout << s.multiply("3","12") << endl;
}
