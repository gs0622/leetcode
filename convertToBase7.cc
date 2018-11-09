#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string convertToBase7(int num) {
		if (!num) return "0";
		int n = abs(num);
		string res;
		while (n!=0) res = to_string(n%7) + res, n/=7;	// what is -8%7?
		return num>0? res: "-"+res;
	}
};
int main(){
	Solution s;
	int n;
	while (cin >> n) cout << s.convertToBase7(n) << endl;

}
