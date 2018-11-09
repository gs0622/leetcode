#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool lemonadeChange1(vector<int>& bill) {
		int five=0, ten=0;
		for (auto b: bill) {
			if (b==5)
				++five;
			else if (b==10) {
				++ten;
				if (five==0) return false;
				--five;
			} else if (b==20) {
				if (ten>0 && five>0) --ten, --five;
				else if (five>=3) five-=3;
				else return false;
			}
		}
		return true;
	}
	// O(n)
	bool lemonadeChange(vector<int>& bills) {
		unordered_map<int,int> mp;
		for (auto b: bills) {
			if (b>5) {
				if (b==10) {
					if (mp[5]==0) return false;
					--mp[5];
				} else if (b==20) {
					if (mp[10]>0 && mp[5]>0) --mp[10], --mp[5];
					else if (mp[5]>=3) mp[5]-=3;
					else return false;
				}
			}
			++mp[b];
		}
		return true;
	}
};
int main(){
	Solution s;
	vector<int> B1{5,5,5,10,20};
	cout << s.lemonadeChange(B1) << " " << s.lemonadeChange1(B1) << endl;
	vector<int> B2{5,5,10};
	cout << s.lemonadeChange(B2) << " " << s.lemonadeChange1(B2) << endl;
	vector<int> B3{10,10};
	cout << s.lemonadeChange(B3) << " " << s.lemonadeChange1(B3) << endl;
	vector<int> B4{5,5,10,10,20};
	cout << s.lemonadeChange(B4) << " " << s.lemonadeChange1(B4) << endl;
}
