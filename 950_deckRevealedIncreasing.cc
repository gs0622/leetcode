#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		int n=deck.size();
		sort(deck.rbegin(), deck.rend());	// reverse order
		deque<int> dq(1,deck[0]);
		for (int i=1; i<n; ++i) {
			dq.push_front(dq.back());	// dup back to front
			dq.pop_back();			// drop back
			dq.push_front(deck[i]);		// stack cur
		}
		return vector<int>(dq.begin(), dq.end());
	}
};
int main(){
	Solution s;
	vector<int> A1{17,13,11,2,3,5,7};
	vector<int> res = s.deckRevealedIncreasing(A1);
	for (auto n: res) cout << n << ' ';
	cout << endl;
;}
