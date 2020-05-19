#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool canReorderDoubled(vector<int>& A) {
		multiset<int> st(A.begin(), A.end());
		int n=A.size();
		vector<int> B;
		for (int i=0; i<n; i+=2) {
			int first = *st.begin();
			auto it1 = st.find(2*first);
			auto it2 = st.find(first/2);
			if (it1==st.end() && it2==st.end()) return false;
			else if (it1 != st.end()) st.erase(it1);
			else st.erase(it2);
			st.erase(st.begin());
		}
		return true;
	}
};
int main(){
	Solution s;
	vector<int> A1{0,0};
	cout << s.canReorderDoubled(A1) << endl;
	vector<int> A2{2,1,2,6};
	cout << s.canReorderDoubled(A2) << endl;
	vector<int> A3{4,-2,2,-4};
	cout << s.canReorderDoubled(A3) << endl;
	vector<int> A4{1,2,4,16,8,4};
	cout << s.canReorderDoubled(A4) << endl;
}
