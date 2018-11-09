#include <iostream>
#include <string>
using namespace std;

class Solution {
    const long long base = 257;
    const long long mod = 1000000007;
    long long pow;
public:
    int strStr(string haystack, string needle) {
        int len_h = haystack.size();
        int len_n = needle.size();
        if (len_n == 0) return 0;
        long long pow, hash_h, hash_n;
        int i, j;
        for (i = 0, hash_n = 0, pow = 1; i < len_n; i++) {
            hash_n = (hash_n * base + needle[i]) % mod;		// hash of needle
            pow = (pow * base) % mod;
        }
        for (i = 0, hash_h = 0; i < len_h; i++) {
            hash_h = (hash_h * base + haystack[i]) % mod;
            if (i >= len_n) {
                hash_h -= haystack[i-len_n] * pow;
                while (hash_h < 0) hash_h += mod;
                //cout << hash_n << " " << hash_h << endl;
            }
            if (hash_h == hash_n) {
                for (j = 0; j < len_n; j++) {
                    int k = i - len_n + 1 + j;
                    if (haystack[k] != needle[j]) break;
                }
                if (j == len_n) return (i >= len_n)? (i - len_n + 1): 0;
            }
        }
        return -1;
    }
};

int main(void) {
    string a("mississippi");
    string b("issi");
    //string a("12345");
    //string b("345");
    Solution s;
    cout << s.strStr(a, b) << endl;
    return 0;
}
