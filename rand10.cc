/* https://leetcode.com/problems/implement-rand10-using-rand7/description/
Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
	int rand7() {
		return rand()%7+1;	// 1-7
	}
public:
	int rand10() {
		int rnd = ((rand7()-1)*7)+rand7();
		return (rnd>=40)? rnd%10+1: rand10();
	}
};
int main(){
	Solution s;
	map<int,int> m;
	srand(time(0));
	for (int i=0; i<1000000; ++i)
		++m[s.rand10()];
	int sum=0;
	for (auto x: m) {
		cout << setw(2) << x.first << ": " << x.second << endl;
		sum+=x.second;
	}
	cout << " T: " << sum << endl;
}
