#include <iostream>
#include <string>
#include <vector>
using namespace std;
// M: 1000, D: 500, C: 100, L: 50, X: 10, V: 5, I: 1
class Solution {
public:
    string intToRoman(int num) {
	vector<vector<string>> r{{"", "M", "MM", "MMM"},
				 {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
				 {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
				 {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}};
	return r[0][num/1000] + r[1][(num%1000)/100] + r[2][(num%100)/10] + r[3][num%10];
    }
};
int main(){
	Solution s;
	cout << s.intToRoman(3999) << endl;
	cout << s.intToRoman(4) << endl;
	cout << s.intToRoman(9) << endl;
	cout << s.intToRoman(99) << endl;
}
