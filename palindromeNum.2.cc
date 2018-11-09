/*
https://leetcode.com/problems/palindrome-number

Determine whether an integer is a palindrome. Do this without extra space.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long y = 0, z = x;
        while (z > 0) {
            y = (y * 10) + (z % 10);
            z /= 10;
        };
        return (y == x);
    }
};

int main(void) {
    Solution s;
    cout << s.isPalindrome(123454321) << endl;
    cout << s.isPalindrome(11) << endl;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(1) << endl;
    cout << s.isPalindrome(12321) << endl;
    cout << s.isPalindrome(23) << endl;
    cout << s.isPalindrome(32) << endl;
    cout << s.isPalindrome(1232) << endl;
    return 0;
}
