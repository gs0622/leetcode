#include <iostream>
#include <string>
using namespace std;

int palidrome(string &s, int left, int right) {
    int len = (right == left)? 1: 0;
    while (left >= 0 && right < s.size()) {
        if (left == right) {
            left--, right++;
            continue;
        }
        if (s[left--] == s[right++]) len += 2;
        else break;
    }
    return len;
}
// O(n^2)
string helper(string &s) {
    size_t sz = s.size();
    size_t max = 0;
    string r;
    for (int i = 0; i < sz; i++) {
        int len1 = palidrome(s, i, i);
        int len2 = palidrome(s, i, i+1);
        //cout << i << ": " << len1 << ": " << len2 << endl;
        if (max < len1)
            max = len1, r = s.substr(i-(len1/2), len1);
        if (max < len2)
            max = len2, r = s.substr(i-(len1/2), len2);
    }
    return r;
}

int main(void) {
    string s;
    while (cin >> s) {
        cout << helper(s) << endl;
    }
}
