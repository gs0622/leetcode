#include <bits/stdc++.h>

using namespace std;

int stringConstruction(string s){
    unordered_map<char, int> m;
    for (char c: s) m[c]++;
    return m.size();
}

int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        int r = stringConstruction(s);
        cout << r << endl;
    }
    return 0;
}
