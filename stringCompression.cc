/* https://leetcode.com/problems/string-compression/description/
In:     ["a","a","b","b","c","c","c"]
Out  6, ["a","2","b","2","c","3"]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int compress(vector<char>& ch) {
		int i, j, cnt, n=ch.size();
		for (i=0, j=1; i<n && j<n; ++j) {
			if (ch[i]!=ch[j]) {
				cnt = j-i;
				++i;
				if (cnt>1) {
					string s = to_string(cnt);
					for (auto c: s) ch[i++] = c;
				}
				ch[i]=ch[j];
				i=j;
			} // else ++j see above 
		}
		cnt = j-i;
		++i;
		if (cnt>1) {
			string s = to_string(cnt);
			for (auto c: s) ch[i++] = c;
		}
		return i;
	}
	int compress1(vector<char>& c) {
		int i, j, n=c.size();
		string s;
		for (i=0, j=1; i<n && j<n; ++j) {
			if (c[i]!=c[j]) {
				s+=c[i];
				if (j-i>1) s += to_string(j-i);
				i=j;
			} // else ++j see above 
		}
		s+=c[i];
		if (j-i>1) s += to_string(j-i);
		//cout << s << endl;
		i=0;
		for (auto t: s) c[i++] = t;
		return i;
	}
	int compress2(vector<char>& c) {
		int i, j, k, n=c.size(), r=n;
		for (i=0; i<n;) {
			for (j=i+1, k=1; j<n; ++j, ++k) {
				if (c[j]!=c[i]) break;
			}
			if (k>2) {
				r-= (j-i-1);
				int t = j-i;
				while (t>=1) r+=1, t/=10;
			}
			i=j;
		}
		return r;
	}
};
int main(){
	Solution s;
	vector<char> c1{'a','a','b','b','c','c','c'};
	cout << s.compress(c1) << endl;
	for (auto c: c1) cout << c << " ";
	cout << endl;
	vector<char> c2{'a'};
	cout << s.compress(c2) << endl;
	vector<char> c3{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	cout << s.compress(c3) << endl;
	for (auto c: c3) cout << c << " ";
	cout << endl;
}
