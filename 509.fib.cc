#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int fib(int n) {
		int a=0, b=1, c;
		for (int i=1; i<n; ++i)
			//c=a+b, a=b, b=c;
			b+=a, a=b-a; // c=a+b, b=c, a=b
		return n<1? a: b;
	}
};
int main(){
	Solution s;
	cout << s.fib(2) << endl; 
	cout << s.fib(3) << endl; 
	cout << s.fib(4) << endl; 
	cout << s.fib(30) << endl; 
}
