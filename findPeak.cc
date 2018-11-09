#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // O(n) time linear solution
    static int findPeak(vector<int> A) {
        int peak = 1;
        for (int i = 1; i < A.size() - 1; i++) {
            if (A[i] > A[i-1] &&
                A[i] > A[i+1]) {
                    peak = i;
                    break;
            }
        }
        return peak;
    }
};

int main(void) {
    int arr[] = {1, 2, 1, 3, 4, 5, 7, 6};
    vector<int> v(arr, arr+8);
    cout << Solution::findPeak(v) << endl;
    return 0;
}


