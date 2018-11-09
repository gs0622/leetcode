#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isUgly2(int num) {
		if (num <= 0) return false;
		int arr[] = {2,3,5};
		for (auto d: arr) {
			while (num % d == 0) num /= d;
		}
		return num == 1;
	}
	bool isUgly(int num) {
		int prev = num;
		while (num != 1) {
			if (num % 2 == 0) num /= 2;
			if (num % 3 == 0) num /= 3;
			if (num % 5 == 0) num /= 5;
			if (prev == num) return false;
			prev = num;
		}
		return true;
	}
};
int main(){
	Solution s;
	cout << s.isUgly2(6) << endl;
	cout << s.isUgly2(8) << endl;
	cout << s.isUgly2(14) << endl;
}
