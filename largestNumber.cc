#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	string largestNumber2(vector<int>& nums) {
		function<bool(string,string)> cmp = [](string a, string b){return (a+b)<(b+a);};
		priority_queue<string, vector<string>, decltype(cmp)> pq;	// in case we prefer streaming ones
		for (auto n: nums)
			pq.push(to_string(n));
		string res;
		while (!pq.empty()) res += pq.top(), pq.pop();
		while (res[0]=='0' && res.size()>1) res.erase(begin(res));
		return res;
	}
	string largestNumber1(vector<int>& nums) {
		struct mycomp {
			bool operator()(string& a, string& b) { return (a+b)<(b+a); }
		};
		priority_queue<string, vector<string>, mycomp> pq;	// in case we prefer streaming ones
		for (auto n: nums)
			pq.push(to_string(n));
		string res;
		while (!pq.empty()) res += pq.top(), pq.pop();
		while (res[0]=='0' && res.size()>1) res.erase(begin(res));
		return res;
	}
	string largestNumber(vector<int>& nums) {
		vector<string> strs;
		for (auto n: nums) strs.push_back(to_string(n));
		sort(begin(strs), end(strs), [](string a, string b){ return (a+b)>(b+a);});
		string res;
		for (auto s: strs) res = res + s;
		while (res[0]=='0' && res.size()>1)	// corner case when it comes to all '0'
			res.erase(0,1);
		return res;
	}
};
int main(){
	Solution s;
	vector<int> nums1{10,2};
	cout << s.largestNumber1(nums1) << endl;
	vector<int> nums2{3,30,34,5,9};
	cout << s.largestNumber1(nums2) << endl;
	vector<int> nums3{0,0,0,0};
	cout << s.largestNumber1(nums3) << endl;
}
