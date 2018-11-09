/* https://leetcode.com/problems/accounts-merge/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		map<string, string> owner;	// emails to owner map
		map<string, string> parents;	// emails table for union-find

		function<string(string)> find = [&](string s){ return parents[s]==s? s: find(parents[s]); };

		for (int i=0; i<accounts.size(); ++i) {				// init
			for (int j=1; j<accounts[i].size(); ++j) {
				parents[accounts[i][j]] = accounts[i][j];	// first parent as itself
				owner[accounts[i][j]] = accounts[i][0];		// map to owner's name
			}
		}

		for (int i=0; i<accounts.size(); ++i) {				// union 1/2
			string p = find(accounts[i][1]);			// tracky: be careful endless find
			for (int j=2; j<accounts[i].size(); ++j) {
				parents[find(accounts[i][j])] = p;
			}
		}

		map<string, set<string>> unions;				// union 1/2: parent email to emails map
		for (int i=0; i<accounts.size(); ++i) {
			for (int j=1; j<accounts[i].size(); ++j)
				unions[find(accounts[i][j])].insert(accounts[i][j]);
		}

		vector<vector<string>> merged;
		for (auto p: unions) {
			vector<string> emails(begin(p.second), end(p.second));
			emails.insert(begin(emails), owner[p.first]);
			merged.push_back(emails);
		}
		return merged;
	}
};
int main(){
	vector<vector<string>> accounts = {
		{"John", "johnsmith@mail.com", "john00@mail.com"},
		{"John", "johnnybravo@mail.com"},
		{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
		{"Mary", "mary@mail.com"}};
	/*
	Output: {
		{"John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'},
		{"John", "johnnybravo@mail.com"},
		{"Mary", "mary@mail.com"}}
	*/
	Solution s;
	vector<vector<string>> res = s.accountsMerge(accounts);
	for_each(begin(res), end(res), [](vector<string> acct){
		for_each(begin(acct), end(acct), [](string s){cout << s << ' ';});
		cout << endl;
	});

	vector<vector<string>> accounts2 = {
		{"Ethan","Ethan1@m.co","Ethan2@m.co","Ethan0@m.co"},
		{"David","David1@m.co","David2@m.co","David0@m.co"},
		{"Lily","Lily0@m.co","Lily0@m.co","Lily4@m.co"},
		{"Gabe","Gabe1@m.co","Gabe4@m.co","Gabe0@m.co"},
		{"Ethan","Ethan2@m.co","Ethan1@m.co","Ethan0@m.co"}
	};
	res = s.accountsMerge(accounts2);
	for_each(begin(res), end(res), [](vector<string> acct){
		for_each(begin(acct), end(acct), [](string s){cout << s << ' ';});
		cout << endl;
	});

};
