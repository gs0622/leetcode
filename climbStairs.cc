/*https://leetcode.com/problems/climbing-stairs/description/*/
#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n) {
    int i, fn, fa = 1, fb = 2;
    if (n < 1) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    for (i = 2; i < n; i++) { // bottom-up fibonacci
            fn = fa + fb; 
            fa = fb, fb = fn; 
    }   
    return fn;
}
int main(){
	cout << climbStairs(2) << endl;
	cout << climbStairs(3) << endl;
}
