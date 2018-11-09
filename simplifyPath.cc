#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		istringstream iss(path);
		string res, tmp;
		vector<string> stk;
		while (getline(iss, tmp, '/')) {		// split by delim
			if (tmp == "" || tmp == ".") continue;
			if (tmp == "..") {
				if (!stk.empty()) stk.pop_back();
				continue;
			}
			stk.push_back(tmp);
		}
		for (auto s: stk) res = res + '/' + s;
		return res.empty()? "/": res;			// corner case of "/"
	}
	string simplifyPath1(string path) {
		size_t beg=0, tok=0;
		stack<string> stk, stk2;
		while ((tok = path.find('/', tok)) != string::npos) {
			//string s = path.substr(beg, tok-beg);	// not include suffix '/'
			string s = path.substr(beg, tok-beg+1);
			cout << s << endl;
			if (s != "/.") {
				if (s == "/.." && !stk.empty())
					stk.pop();
				else
					stk.push(path.substr(beg, tok-beg));
			}
			beg = tok;
			++tok;
		}
		string res;
		while (!stk.empty())
			res += stk.top(), stk.pop();

		return res;
	}
};
int main(){
	Solution s;
	string p1{"/a/./b/../../c/"};
	//cout << s.simplifyPath(p1) << endl;
	string p2{"/home/"};
	//cout << s.simplifyPath(p2) << endl;
	string p3{"/abc/..."};
	cout << s.simplifyPath(p3) << endl;
}
