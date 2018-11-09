/* Given a compressed string in which a number followed by []
indicate how many times those characters occur, decompress the string
*/
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

string decode(string s, int len, int& i) {
    string r;
    while (i < len && s[i] != ']') { // pop while ']'
        if (isdigit(s[i])) {
            int n = 0;
            while (isdigit(s[i]) && i < len) { // atoi
                n = n * 10 + s[i++] - '0';
            }
            // number followed by [t]
            i++; // '['
            string t = decode(s, len, i); // push w/ referenced i
            i++; // ']'
            while (n--) r += t; // repeat
        } else r += s[i++];
    }
    return r;
}

int main(void) {
    string s;
    cin >> s;
    int i = 0;
    string t = decode(s, s.length(), i);
    cout << t << endl;
    return 0;
}
