/*
Given a contiguous sequence of numbers in which each number repeats thrice, 
there is exactly one missing number. Find the missing number.
eg: 11122333 : Missing number 2
11122233344455666 Missing number 5
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// find missing by XOR
int getMissing(vector<int> v) {
    int a = 0, b = 0;
    for (auto x: v) a ^= x;
    for (int i = v.front(); i <= v.back(); i++) b ^= i;
    a ^= b;
    return a;
}

int getMissing2(vector<int> v) {
    int sumA, sumB = 0;

    sumA = (v.front() + v.back()) * (v.size() + 1) / 2;
    for (auto x: v) sumB += x;

    return sumA - sumB;
}

int main(void) {
    int x;
    map<int, int> m;
    vector<int> v;
    while (cin >> x) {
        m[x]++;
        v.push_back(x);
    }
    for (auto y: m) cout << y.first << " " << y.second << endl;
    x = getMissing(v); // XOR method
    cout << x << endl;
    x = getMissing2(v);
    cout << x << endl; // sum method
    return 0;
}
