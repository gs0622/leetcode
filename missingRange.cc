#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> missing(vector<int>& v) {
    int s, e, i;
    vector<string> r;
    if (0 == v.size()) {
        r.push_back("0->99");
        return r;
    }
    for (i = 1, s = i; i < v.size(); i++) {
        if (v[i] - v[i-1] == 1) {
            s = i+1;
            continue;
        }
        e = v[i] - 1;
        if (e == s) r.push_back(to_string(s));
        else        r.push_back(to_string(s) + "->" + to_string(e));
        s = v[i]+1;
    }
    if (v[i-1] < 99) r.push_back(to_string(s) + "->99");
    return r;
}

int main(void) {
    int a[] = {0, 1, 3, 50, 75};
    int b[100];
    for (int i = 0; i < 100; i++) b[i] = i;
    //vector<int> v(a, a+5);
    //vector<int> v;
    vector<int> v(b, b+100);
    // TBD: assert if arr is not sorted
    vector<string> r = missing(v);
    for (auto x: r) cout << x << " ";
    cout << endl;
    return 0;
 }
