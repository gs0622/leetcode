#include <functional>
#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string s;
    hash<string> h;
    while (cin >> s) {
        cout << h(s) << endl;
    }
    return 0;
}
