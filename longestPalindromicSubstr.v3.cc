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
    int max = 0;
    int start = 0, stop = 0;
    string r;
    for (int i = 0; i < s.size(); i++) {
        int len1 = palidrome(s, i, i);
        int len2 = palidrome(s, i, i+1);
        int len = std::max(len1, len2);
        cout << i << ": " << len1 << ": " << len2 << endl;
        if (len > stop - start)
            start = i - ((len - 1) / 2), stop = i + (len / 2);
    }
    return s.substr(start, stop - start + 1);
}

int main(void) {
    string s;
    while (cin >> s) {
        cout << helper(s) << endl;
    }
}
