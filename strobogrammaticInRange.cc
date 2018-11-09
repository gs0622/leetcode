#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// starts from empty, 0, 1, 8, recusively expand wrapping w/ 0+s+0, 1+s+1, 6+s+9...
	int strobogrammaticInRange(string low, string high) {
		int res=0;
		function<void(string)> dfs=[&](string s){
			if (s.size()>=low.size() && s.size()<=high.size()) {
				if (s.size()==low.size() && s.compare(low)<0)
					return;
				if (s.size()==high.size() && s.compare(high)>0)
					return;
				if (!(s.size()>1 && s[0]=='0'))	// debug: examine strobogrammatic num here
					++res;
			}
			if (s.size()+2>high.size())
				return;
			dfs("0"+s+"0");	
			dfs("1"+s+"1");	
			dfs("6"+s+"9");	
			dfs("8"+s+"8");	
			dfs("9"+s+"6");	
		};
		dfs("");
		dfs("0");
		dfs("1");
		dfs("8");
		return res;
	}
};
int main(){
	Solution s;
	cout << s.strobogrammaticInRange("50","100") << endl;
}
