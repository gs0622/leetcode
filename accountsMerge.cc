/*
https://leetcode.com/problems/accounts-merge/description/
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [
  ["John", "johnsmith@mail.com", "john00@mail.com"],
  ["John", "johnnybravo@mail.com"],
  ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
  ["Mary", "mary@mail.com"]
]
Output: [
  ["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
  ["John", "johnnybravo@mail.com"],
  ["Mary", "mary@mail.com"]
]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		map<string, string> owner;	  // {email: owner}
		map<string, string> parents;	// {email: email} for union-find

		function<string(string)> find = [&](string s){ return parents[s]==s? s: find(parents[s]); };

		for (int i=0; i<accounts.size(); ++i) {				// translate accts to two maps
			for (int j=1; j<accounts[i].size(); ++j) {  // skip name
				parents[accounts[i][j]] = accounts[i][j];	// first parent as itself
				owner[accounts[i][j]] = accounts[i][0];		// map each acct email to the owner's name
			}
		}

		for (int i=0; i<accounts.size(); ++i) {				// union 1/2
			string p = find(accounts[i][1]);			      // union to the 1st email; tricky: be careful endless find
			for (int j=2; j<accounts[i].size(); ++j) {
				parents[find(accounts[i][j])] = p;
			}
		}

		map<string, set<string>> unions;		          // union 2/2: grouping {parent email: [emails set]}
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
