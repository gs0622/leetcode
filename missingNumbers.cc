#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m, tmp;
    map<int, int> m1, m2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        m1[tmp]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        m2[tmp]++;
    }
    for (auto x: m2) {
        map<int, int>::const_iterator it = m1.find(x.first);
        if (it->second < x.second) cout << x.first << " ";
    }
    cout << endl;
    return 0;
}

