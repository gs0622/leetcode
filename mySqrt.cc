#include <iostream>
using namespace std;
class Solution {
public:
	int mySqrt1(int x) {
		long long r = x;
		while (r*r > x)
			r = (r + x/r)/2;
		return (int)r;
	}
	int mySqrt(int x) {
		int lo=1,hi=x;
		while (lo<=hi){
			int mi=lo+(hi-lo)/2;
			if (mi == x/mi) return mi;
			else if (mi < x/mi) lo=mi+1;
			else hi=mi-1; 
		}
		return hi;
	}
	int mySqrt3(int x) {
		long long mi,lo=1,hi=x;
		while (lo<=hi){
			mi=lo+(hi-lo)/2;
			long long quadric = mi*mi;
			if (quadric == x) return mi;
			else if (quadric < x) lo=mi+1;
			else hi=mi-1; 
		}
		return hi;
	}
};
int main(){
	Solution s;
	cout << s.mySqrt(4) << endl;
	cout << s.mySqrt(8) << endl;
	cout << s.mySqrt(9) << endl;
	cout << s.mySqrt(1) << endl;
	cout << s.mySqrt(2147395599) << endl;
	//cout << s.mySqrt2(2147395599) << endl;
}
