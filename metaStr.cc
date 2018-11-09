#include<bitset>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool areMetaStrings(string str1, string str2) {
		std::bitset<256> bits1, bits2;
		int cnt = 0;
		if (str1.size() != str2.size())
			return false;
		for (int i=0; i<str1.size(); ++i) {
			bits1[str1[i]] = 1;
			bits2[str2[i]] = 1;
			if (str1[i] ^ str2[i])
				cnt+=1;
			//cout << str1[i] << " " << str2[i] << ": " << (str1[i] ^ str2[i]) << ": " << cnt << endl;
		}
		//cout << bits1 << endl;
		//cout << bits2 << endl;
		//cout << cnt << ": " << (bits1 == bits2) << endl;
		return bits1 == bits2 && cnt <= 2;
	}
};
int test1();
int test2();
int main(){
	test1();
	test2();
}
int test1() {
	string s1("geeks");
	string s2("keegs");
	Solution s;
	cout << s.areMetaStrings(s1, s2) << endl;
}
int test2() {
	string s1("rsting");
	string s2("string");
	Solution s;
	cout << s.areMetaStrings(s1, s2) << endl;
}
