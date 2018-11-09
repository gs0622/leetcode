#include <iostream>
#include <cstdlib>
using namespace std;

// Consider case of int overflow
int reverseInt(int n) {
    int v = 0;
    while (n) {
        //if (abs(v) > INT_MAX/10 /*(2^31)/10*/) return 0;
        if (abs(v) > 214748364 /*(2^31)/10*/) return 0;
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
