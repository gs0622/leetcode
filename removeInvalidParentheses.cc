#include <bits/stdc++.h>
using namespace std;
class Solution {
	bool valid(string s) {
		int cnt=0;
		for (int i=0; i<s.size(); ++i) {
			if (s[i]=='(') ++cnt;
			else if (s[i]==')') {
				if (cnt>0) --cnt;
				else return false;
			}
		}
		return cnt==0;
	}
public:
	// dfs
        vector<string> removeInvalidParentheses3(string s) {
		vector<string> res;
		function<void(int,int,string,string)> dfs=[&](int p, int lastRm, string dir, string ss){
			for (int i=p, cnt=0; i<ss.size(); ++i) {
				if (ss[i]==dir[0]) ++cnt;
				else if (ss[i]==dir[1]) --cnt;
				if (cnt>=0) continue;
				for (int j=lastRm; j<=i; ++j) {
					if (ss[j]==dir[1] && (j==lastRm || ss[j-1]!=dir[1]))
						dfs(i,j,dir,ss.substr(0,j)+ss.substr(j+1));
				}
				return;
			}
			reverse(begin(ss), end(ss));
			if (dir[0]=='(')
				dfs(0,0,")(",ss);
			else 
				res.push_back(ss);
		};
		dfs(0,0,"()",s);
		return res;
        }
	// dfs
        vector<string> removeInvalidParentheses2(string s) {
		vector<string> res;
		unordered_set<string> ans;
		string cur;				// starting empty node
		function<void(int,string)> helper=[&](int p, string cur) {
			if (p==s.size()) {
				if (valid(cur)) ans.insert(cur);
				return;
			}
		};
		return res;
	}
	// naive backtracing dfs, generate 2^n substr, hashset to remove dup
        vector<string> removeInvalidParentheses1(string s) {
		vector<string> res;
		unordered_set<string> ans;
		string cur;				// starting empty node
		function<void(int,string)> helper=[&](int p, string cur) {
			if (p==s.size()) {
				if (valid(cur))
					ans.insert(cur);
				return;
			}
			cur+=s[p];
			helper(p+1,cur);		// choose this char
			cur.pop_back();			// backtracing
			if (s[p]=='('||s[p]==')')	// not-choose this '(' or ')'
				helper(p+1,cur);
		};
		helper(0,cur);
		size_t n=0;
		for (auto& str: ans)			// find longest len among all answers
			n=max(n,str.size());
		for (auto& str: ans)			// find longest string to return
			if (str.size()==n)
				res.push_back(str);
		return res;
	}
	// bfs
	vector<string> removeInvalidParentheses4(string s) {
		vector<string> res;
		queue<tuple<string,int,int,char>> q;
		q.push(make_tuple(s,0,0,'('));
		while (!q.empty()) {
			auto top=q.front(); q.pop();
			string ss=get<0>(top);
			int start=get<1>(top), lastRm=get<2>(top), cnt=0;
			char L=get<3>(top), R=(L=='(')?')':'(';
			for (int i=start; i<ss.size(); ++i) {
				if (ss[i]==L) ++cnt;
				else if (ss[i]==R) --cnt;
				if (cnt>=0) continue;
				for (int j=lastRm; j<=i; ++j) {
					if (ss[j]==R && (j==lastRm || ss[j-1]!=R))
						q.push(make_tuple(ss.substr(0,j)+ss.substr(j+1),i,j,L));
				}
				break;
			}
			if (cnt<0) continue;
			reverse(begin(ss),end(ss));
			if (L=='(')
				q.push(make_tuple(ss,0,0,')'));
			else
				res.push_back(ss);
		}
		return res;
	}
	// bfs
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		unordered_set<string> ans;
		queue<string> q;
		q.push(s);
		while (!q.empty()) {
			string ss=q.front(); q.pop();
			if (ans.count(ss))
				continue;
			ans.insert(ss);		// no matter valid or invalid parentheses
			if (valid(ss))
				res.push_back(ss);
			else if (res.empty()) {	// guarantee minimal
				for (int i=0; i<ss.size(); ++i)
					if (ss[i]==')'||ss[i]=='(') {	// consider to remve each one char of ss
						//q.push(ss.substr(0,i)+ss.substr(i+1));	// strip ss[i], split to two substr
						string ss1=ss.substr(0,i);
						string ss2=ss.substr(i+1);
						q.push(ss1+ss2);	// strip ss[i], split to two substr
					}
			}
		}
		return res;
	}
};
int main(){
	Solution s;
	string s1{"()())()"};
	vector<string> strs;
	strs = s.removeInvalidParentheses(s1);
	for (auto ss: strs) cout << ss << ' ';
	cout << endl;
	strs = s.removeInvalidParentheses1(s1);
	for (auto ss: strs) cout << ss << ' ';
	cout << endl;
	strs = s.removeInvalidParentheses4(s1);
	for (auto ss: strs) cout << ss << ' ';
	cout << endl;
}
