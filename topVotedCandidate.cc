#include <bits/stdc++.h>
using namespace std;
class TopVotedCandidate {
	map<int,int> mp;	// time-person map, keep time as key in order, will be time-lead map
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		int n = persons.size(), lead=-1;
		unordered_map<int,int> cnt;	// person-vote map
		for (int i=0; i<n; ++i)
			mp[times[i]] = persons[i];
		for (auto it: mp) {		// in order of time
			if (++cnt[it.second] >= cnt[lead])
				lead = it.second;
			mp[it.first] = lead;	// transfer to time-lead map
		}
	}
	int q(int t) {
		return (--mp.upper_bound(t))->second;	// find greater than t, rollback it one to acces time-lead map
	}
};

int main(){
	vector<int> P{0,1,1,0,0,1,0}, T{0,5,10,15,20,25,30};
	TopVotedCandidate vote(P,T);
	cout << vote.q()
