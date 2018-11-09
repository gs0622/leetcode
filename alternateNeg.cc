#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool sameSign(int x, int y)
{
    return (x >= 0) ^ (y < 0);
}

int main(void) {
    int n;
    vector<int> in;
    while (cin >> n) in.push_back(n);
    for (auto x: in) cout << x << " ";
    cout << endl;
    queue<int> q;
    bool expectNeg = (in[0] < 0)? false: true;
    for (int i = 1; i < in.size(); i++) {
        int x = in[i];
        int j = i;
        while ((expectNeg ^ in[j] < 0 ||
            !expectNeg ^ in[j] >= 0) && j < in.size()) {
            j++;
        }
        if (j != in.size()) {
            // locate one to switch
            in[i] = in[j];
            in[j] = x;
            expectNeg = !expectNeg;
        }
    }
    for (auto x: in) cout << x << " ";
    cout << endl;
    
    return 0;
}
