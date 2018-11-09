#include <cmath>
#include <iostream>
#include <string>
using namespace std;
// The range of n is [3, 10^18].
// The string representing n is always valid and will not have leading zeros.
class Solution {
public:
	O(log(n)^2)
	string smallestGoodBase(string n) {
		uint64_t num = stoll(n), p;
		for (p=log(num+1)/log(2); p>=2; --p) { // start from the largest power
			uint64_t mi, lo=2, hi=pow(num,1.0/(p-1))+1;
			cout << p << ": " << hi << endl;
			while (lo<=hi) {
				mi=lo+(hi-lo)/2;
				cout << mi << endl;
				uint64_t sum=0;
				for (uint64_t i=0, f=1; i<p; ++i, f*=mi)
					sum+=f;
				if (sum < num) lo=mi+1;
				else if (sum > num) hi=mi-1;
				else return to_string(mi);
			}
		}
		return to_string(num-1);
	}
	string smallestGoodBase2(string n) {
		unsigned long long num = stoll(n);
		unsigned long long i, tmp;
		bool yes;
		for (i=2; i<num; ++i) {
			tmp = num;
			while (tmp % i == 1 && tmp > i) tmp /= i;
			if (tmp == 1) return to_string(i);
		}
		return n;
	}
};
int main(){
	Solution s;
	//string s1{"13"};
	//cout << s.smallestGoodBase(s1) << endl;
	//string s2{"4681"};
	//cout << s.smallestGoodBase(s2) << endl;
	string s3{"1000000000000000000"};
	cout << s.smallestGoodBase(s3) << endl;
}

