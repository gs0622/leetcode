#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int exchangeSeats1(vector<int>& B, vector<int>& A) {
		string AA(A.begin(), A.end()), BB(B.begin(), B.end());
		queue<string> q;
		unordered_set<string> visit;
		q.push(BB);
		int res=0;
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {
				string CC=q.front(); q.pop();
				if (CC==AA)
					return res;
				visit.insert(CC);
				int empty=CC.find('0');
				for (int j=0; j<CC.size(); ++j) {
					if (j!=empty) {
						swap(CC[j], CC[empty]);
						if (visit.count(CC))
							q.push(CC);
						swap(CC[j], CC[empty]);
					}
				}
			}
			++res;
		}
		return -1;
	}
	int exchangeSeats(vector<int>& B, vector<int>& A) {
		int res=0, empty;
		queue<vector<int>> q;
		set<vector<int>> visit;
		q.push(B);
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {			// level order BFS
				vector<int> C=q.front(); q.pop();
				if (C==A)
					return res;			// found
				visit.insert(C);			// visit
				for (int j=0; j<C.size(); ++j) {	// find empty of current state
					if (C[j]==0) {
						empty=j;
						break;
					}
				}
				for (int j=0; j<C.size(); ++j) {	// enumerate all next states
					if (j!=empty) {
						swap(C[j],C[empty]);
						if (visit.count(C)==0)	// not visited yet
							q.push(C);
						swap(C[j],C[empty]);
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
	vector<int> before1{1,2,0,3,4}, after1{1,0,2,3,4}, after2{2,4,0,1,3};
	cout << s.exchangeSeats(before1, after1) << ' ' << s.exchangeSeats(before1, after1) << endl;
	cout << s.exchangeSeats(before1, after2) << ' ' << s.exchangeSeats(before1, after2) << endl;
}
