#include <iostream>
using namespace std;

// Extend int to long to ignore int overflow
long reverseInt(int n) {
    long v = 0;
    while (n) {
        v = v * 10 + n % 10;
        n /= 10;
    }
    return v;
}

int main(void) {
    int n;
    while (cin >> n) {
        cout << reverseInt(n) << endl;
    }
    return 0;
}
