/* https://leetcode.com/problems/validate-ip-address/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string validIPAddress(string s) {
		// TBD
		istringstream iss(s);
		string tmp;
		if (count(begin(s), end(s), '.') == 3) {
			for (int i=0; i<4; ++i) {
				getline(iss, tmp, '.');
				try {
					if (tmp.empty() || tmp[0]=='0' || stoi(tmp)>254)
						return "Neighter";
				} catch (std::invalid_argument) {
					return "Neighter";
				}
			}

		} else if (count(begin(s), end(s), ':') == 7)
		}
		return "Neighter";
	}
	string validIPAddress1(string s) {
		size_t tok = s.find_first_of(".:");
		if (tok == string::npos) return "Neighter";

		istringstream iss(s);
		string tmp;
		if (s[tok] == '.') { // check IPv4
			int cnt = 0;
			while (getline(iss, tmp, '.')) {
				if (tmp.empty() || tmp.size()>3 || tmp[0]=='0' || stoi(tmp)>254)
					return "Neighter";
				++cnt;
			}
			return (cnt == 4)? "IPv4": "Neighter";
		} else {
			int cnt = 0;
			while (getline(iss, tmp, ':')) {
				if (tmp.empty() || tmp.size()!=4 && stoi(tmp)!=0) return "Neighter";
				if (tmp.size()==4) {
					for (int i=0; i<4; ++i)
						if (!isalnum(tmp[i])) return "Neighter";
				} else {
					if (tmp.size()!=1 || stoi(tmp)!=0) return "Neighter";
				}
				++cnt;	
		}
			return (cnt == 8)? "IPv6": "Neighter";
		}
	}
};
int main(){
	Solution s;
	string s1{"172.16.254.1"};
	cout << s.validIPAddress(s1) << endl;
	string s2{"2001:0db8:85a3:0:0:8A2E:0370:7334"};
	cout << s.validIPAddress(s2) << endl;
	string s3{"256.256.256.256"};
	cout << s.validIPAddress(s3) << endl;
	string s4{"12..33.4"};
	cout << s.validIPAddress(s4) << endl;
	string s5{"A.a.aA.2"};
	cout << s.validIPAddress(s5) << endl;
}
