#include <bits/stdc++.h>
using namespace std;
/*
   X 0 1 2 3 4
 Y 0 0 1 2 3 4
   1 5 6 0 1 2
   2 3 4 5 6 0
   3 1 2 3 4 5
   4 6 - - - -
*/
class Solution {
	int rand5() {
		return rand()%5;
	}
	int rand2() {
		int x = rand5();
		if (x==4) return rand2();
		return x%2;
	}
public:
	int rand7v2() {
		int x = 4*rand2()+2*rand2()+rand2();
		if (x==7) return rand7v2();
		return x;
	}
	int rand7() {
		int sum;
		do {
			sum = 5*rand5()+rand5();
		} while (sum > 20);
		return sum % 7;
	}
	int rand7ng() {
		return (rand5()+rand5())%7;
	}
};
int main(){
	Solution s;
	map<int,int> m;
	srand(time(0));
	for (int i=0; i<1000000; ++i)
		++m[s.rand7ng()];
	int sum=0;
	for (auto x: m) {
		cout << x.first << ": " << x.second << endl;
		sum+=x.second;
	}
	cout << "T: " << sum << endl;
}
