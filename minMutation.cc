#include <bits/stdc++.h>
using namespace std;
class Solution {
	const string gene{"ACGT"};
public:
	int minMutation(string S, string E, vector<string>& B) {
		unordered_set<string> bank{B.begin(), B.end()}, visit;
		queue<string> q;
		q.push(S);
		int res=0;
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {
				string s=q.front(); q.pop();
				if (s==E) return res;
				for (int j=0; j<s.size(); ++j) {
					for (int k=0; k<gene.size(); ++k) {
						if (s[j]!=gene[k]) {
							char tmp = s[j];
							s[j]=gene[k];
							if (bank.count(s) && !visit.count(s))
								q.push(s), visit.insert(s);
							s[j]=tmp;
						}
					}
				}
			}
			++res;
		}
		return -1;
	}
};
int main(){
	Solution s;
	vector<string> B1{"AACCGGTA"};
	vector<string> B2{"AACCGGTA", "AACCGCTA", "AAACGGTA"};
	vector<string> B3{"AAAACCCC", "AAACCCCC", "AACCCCCC"};
	vector<string> B4{"AAAAAAAA","AAAAAAAC","AAAAAACC","AAAAACCC","AAAACCCC","AACACCCC","ACCACCCC","ACCCCCCC","CCCCCCCA"};
	cout << s.minMutation("AACCGGTT","AACCGGTA",B1) << endl;
	cout << s.minMutation("AACCGGTT","AAACGGTA",B2) << endl;
	cout << s.minMutation("AAAAACCC","AACCCCCC",B3) << endl;
	cout << s.minMutation("AAAAAAAA","CCCCCCCC",B4) << endl;
}
