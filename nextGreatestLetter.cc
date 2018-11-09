#include <iostream>
#include <vector>
using namespace std;
class Solution {
	char search(vector<char>& letters, char target) {
		int mi, lo = 0, hi = letters.size()-1;
		while (lo <= hi) {
			mi = lo+(hi-lo)/2;
			if (letters[mi] == target)
				break; //return letters[(mi+1) % letters.size()];
			if (letters[mi] > target)
				hi = mi-1;
			else // letters[mi] < target
				lo = mi+1;
		}
		//return letters[lo+1];
		return letters[mi] > target? letters[mi]: letters[(mi+1) % letters.size()];
	}
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		return search(letters, target);
	}
	char nextGreatestLetter2(vector<char>& letters, char target) {
		for (auto c: letters) {
			if (c > target) return c;
		}
		return letters[0];
	}
};
int test1() {
	vector<char> letters {'c', 'f', 'j'};
	Solution s;
	cout << s.nextGreatestLetter(letters, 'a') << ": "
		<< s.nextGreatestLetter2(letters, 'a') << endl;
}
int test2() {
	vector<char> letters {'c', 'f', 'j'};
	Solution s;
	cout << s.nextGreatestLetter(letters, 'd') << ": "
		<< s.nextGreatestLetter2(letters, 'd') << endl;
}
int test3() {
	vector<char> letters {'c', 'f', 'j'};
	Solution s;
	cout << s.nextGreatestLetter(letters, 'g') << ": "
		<< s.nextGreatestLetter2(letters, 'g') << endl;
}
int test4() {
	vector<char> letters {'c', 'f', 'j'};
	Solution s;
	cout << s.nextGreatestLetter(letters, 'j') << ": "
		<< s.nextGreatestLetter2(letters, 'j') << endl;
}
int test5() {
	vector<char> letters {'c', 'f', 'j'};
	Solution s;
	cout << s.nextGreatestLetter(letters, 'k') << ": "
		<< s.nextGreatestLetter2(letters, 'k') << endl;
}
int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
}
