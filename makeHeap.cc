#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int a[] = {10,20,30,5,15};
    vector<int> v(a, a+5);
    make_heap(v.begin(), v.end(), std::greater<int>());	// 5 10 30 20 15 
    for (auto x: v) cout << x << " ";
    cout << endl;

    make_heap(v.begin(), v.end());			// 30 20 5 10 15
    for (auto x: v) cout << x << " ";
    cout << endl;
    return 0;
}
