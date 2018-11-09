/* https://leetcode.com/problems/additive-number/description/
string

Note that the length of first two numbers can't be longer than half of the initial string,
so the two loops in the first function will end when i>num.size()/2 and j>(num.size()-i)/2, this will actually save a lot of time.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isAdditiveNumber1(string num) {
		function<string(string,string)> add=[](string a, string b) {
			int i=a.size()-1, j=b.size()-1, carry=0;
			string res;
			while (i>=0 || j>=0) {
				int sum=(i>=0?a[i--]-'0':0) + (j>=0?b[j--]-'0':0) + carry;
				res = to_string(sum%10) + res;
				carry = sum/10;
			}
			if (carry) res = "1"+res;
			return res;
		};
		function<bool(string,string,string)> helper=[&](string s1, string s2, string rest) {
			if (s1.size()>1 && s1[0]=='0') return false;
			if (s2.size()>1 && s2[0]=='0') return false;
			string sum = add(s1,s2);
			if (sum == rest) return true;	// done
			if (sum.size()>rest.size() || rest.compare(0,sum.size(),sum)!=0) return false; // e.g. sum==100, rest: 100....blah
			return helper(s2, sum, rest.substr(sum.size()));	// rest: cut prefix of sum
		};
		int n=num.size();
		for (int i=1; i<=n/2; ++i) {
			for (int j=1; j<=(n-i)/2; ++j) {
				string s1=num.substr(0,i), s2=num.substr(i,j), rest=num.substr(i+j);
				if (helper(s1,s2,rest))
					return true;
			}
		}
		return false;
	}
	bool isAdditiveNumber(string num) {
		int n=num.size();
		for (int i=1; i<=n/2; i++) {
			for (int j=1; j<=(n-i)/2; j++) {
				string s1=num.substr(0,i), s2=num.substr(i,j), s3=num.substr(i+j);
				if (check(num.substr(0,i), num.substr(i,j), num.substr(i+j)))
					return true;
			}
		}
		return false;
        }
        bool check(string num1, string num2, string num){
		if (num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
		string sum=add(num1, num2);
		if (num==sum) return true;
		if (num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
		else return check(num2, sum, num.substr(sum.size()));
        } 
        string add(string n, string m){
            string res;
            int i=n.size()-1, j=m.size()-1, carry=0;
            while(i>=0 || j>=0){
                int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
                res.push_back(sum%10+'0');
                carry=sum/10;
            }
            if(carry) res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
};
int main(){
	Solution s;
	cout << s.isAdditiveNumber("199100199") << endl;
	cout << s.isAdditiveNumber1("199100199") << endl;
}

