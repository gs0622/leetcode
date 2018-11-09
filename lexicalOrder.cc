#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> lexicalOrder1(int n) {
		vector<int> res;
		for (int i=1, cur=1; i<=n; ++i) {
			res.push_back(cur);
			if (cur*10<=n)
				cur*=10;
			else {
				if (cur>=n)		// cur has been pushed into res
					cur/=10;
				cur+=1;
				while (cur%10==0)	// e.g. 50(not inlist)->5(inlist)->50->51
					cur/=10;
			}
		}
		return res;
	}
	// naive brute force by string comparing hashmap
	vector<int> lexicalOrder(int n) {
		vector<int> res;
		map<string, int> mps;
		for (int i=1; i<=n; ++i) mps[to_string(i)]=i;
		for (auto n: mps) res.push_back(n.second);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> res;
	//res = s.lexicalOrder(14959);
	res = s.lexicalOrder1(19);
	for (auto n: res) cout << n << ' ';
	cout << endl;
	res = s.lexicalOrder1(109);
	for (auto n: res) cout << n << ' ';
	cout << endl;
}
