/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maximumSwap1(int num) {
		string s=to_string(num);
		if (s.size()==1) return num;	// no swap
		int res = num;
		for (int i=1; i<s.size(); ++i) {
			string ss = s;
			for (int j=i; j>=0; --j) {
				swap(ss[i], ss[j]);
				int tmp = stoi(ss);
				res = max(res, tmp);
				swap(ss[i], ss[j]);
			}
		}
		return res;
	}
	int maximumSwap(int num) {
		string s=to_string(num);				// easy to get digits count/index
		vector<int> idx(10,-1);
		for (int i=0; i<s.size(); ++i)
			idx[s[i]-'0']=i;				// save lowest digit index; digit-index map
		for (int i=0,j; i<s.size(); ++i) {
			for (j=9; j>s[i]-'0' && idx[j]==-1; --j);	// idx[j]!=-1 then
			if (j>s[i]-'0') {				// tricky: j > digit[i], greedy
				swap(s[i], s[idx[j]]);
				break;
			}
			if (i==idx[s[i]-'0']) idx[s[i]-'0']=-1;		// tricky: exclude i from idx, e.g., 999xx
		}
		return stoi(s);
	}
};
int main(){
	Solution s;
	cout << s.maximumSwap(2763) << " " << s.maximumSwap1(2763) << endl;
	cout << s.maximumSwap(98368) << " " << s.maximumSwap1(98368) << endl;
	//cout << s.maximumSwap(98368) << endl;
}
