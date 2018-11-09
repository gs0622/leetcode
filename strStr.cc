#include <iostream>
#include <string>
using namespace std;

// Brute-force solution, O(nm) time.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        int len_h = haystack.size();
        int len_n = needle.size();
        if (len_h < len_n) return -1;
        for (i = 0; i < len_h - len_n + 1; i++) {
            for (j = 0; j < needle.size(); j++)
                if (haystack[i+j] != needle[j]) break;
            if (j == len_n) return i;
        }
        return -1;
    }
    int strStr_v2(string haystack, string needle) {
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == needle.size()) return i;
                if (i + j > haystack.size()) return -1;
                if (haystack[i+j] != needle[j]) break;
            }
        }
    }
};

int main(void) {
    //string a("mississippi");
    //string b("issi");
    string a("aaabbbccc");
    string b("");
    Solution s;
    cout << s.strStr(a, b) << endl;
    return 0;
}
