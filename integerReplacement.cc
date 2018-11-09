#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
	int integerReplacement(int n) {
		if (n<=1) return 0; // base case
		if (n%2) return 2 + std::min(integerReplacement(n/2)/*n-1*/, integerReplacement((n/2)+1)/*n+1*/);
		else return 1 + integerReplacement(n/2);
	}
	int integerReplacement2(int n) {
		int cnt=0;
		if (n==INT_MAX) return 32;
		while (n>1) {
			if (n==3) return cnt+2;
			if (n%4==3) n+=1;
			else if (n%2==0) n/=2;
			else n-=1;
			cnt++;
		}
		return cnt;
	}
};
int main(){
	Solution s;
	vector<int> test{8, 3, INT_MAX, INT_MIN};
	for (auto t: test)
		cout << s.integerReplacement(t) << " " << s.integerReplacement2(t) << endl;
}
