#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		//std::function<bool(pair<string,int>, pair<string, int>)> Comparator;
		constexpr bool mycomp = [](const pair<string,int> a, const pair<string,int> b) { return a.second < b.second; };
		map<string,int,mycomp()> m;
		for (auto cp: cpdomains) {
			auto pos1 = cp.find_first_of(" ", 0);
			assert(pos1 != string::npos);
			int cnt = stoi(cp.substr(0, pos1));
			string dom = cp.substr(pos1+1, cp.size()-pos1);
			m[dom] += cnt;
			auto pos2 = dom.find_first_of(".", 0);
			while (pos2 != string::npos) {
				string subdom = dom.substr(pos2+1, distance(begin(dom)+pos2+1, end(dom)));
				pos2 = dom.find_first_of(".", pos2+1);
				m[subdom] += cnt;
			}
		}
		vector<string> res;
		for (auto p: m) res.push_back(to_string(p.second) + " " + p.first);
		return res;
	}
	vector<string> subdomainVisits1(vector<string>& cpdomains) {
		unordered_map<string,int> m;
		for (auto cp: cpdomains) {
			auto pos1 = cp.find_first_of(" ", 0);
			assert(pos1 != string::npos);
			int cnt = stoi(cp.substr(0, pos1));
			string dom = cp.substr(pos1+1, cp.size()-pos1);
			m[dom] += cnt;
			auto pos2 = dom.find_first_of(".", 0);
			while (pos2 != string::npos) {
				string subdom = dom.substr(pos2+1, distance(begin(dom)+pos2+1, end(dom)));
				pos2 = dom.find_first_of(".", pos2+1);
				m[subdom] += cnt;
			}
		}
		vector<string> res;
		for (auto p: m) res.push_back(to_string(p.second) + " " + p.first);
		return res;
	}
};
int main(){
	Solution so;
	vector<string> res;
	//vector<string> s{"9001 discuss.leetcode.com"};
	vector<string> s{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
	res = so.subdomainVisits(s);
	copy(begin(res), end(res), ostream_iterator<string>(cout, " "));
	cout << endl;
}
