#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // O(n) liner approach
    static int findPeak0(vector<int> A) {
        int max = 0;
        for (int i = 0; i < A.size()-1; i++) {
            if (A[i] > A[max]) max = i;
        }
        return max;
    }
    // O(log(n)) time binary search approach
    static int findPeak1(vector<int> A) {
	if (A.size() < 2) return 0;
        int lo = 0, hi = A.size() - 1, mid = lo;
        while (lo < hi) {
            mid = lo + (hi - lo)/2;
            if (A[mid] < A[mid+1]) lo = mid+1;
            else  hi = mid;
        }
        return lo;
    }
    // O(log(n)) time binary search approach for folded sorting arr
    static int findPeak2(vector<int> A) {
        int lo = 0, hi = A.size() - 1, mi;
        while (lo < hi) {
            mi = lo + (hi - lo)/2;
            if (A[mi] > A[hi]) lo = mi, hi-=1;
            else hi = mi-1;
        }
        return lo;
    }
    // O(log(n)) time local peak binary search approach
    static int findPeak3(vector<int> A) {
        int lo = 0, hi = A.size() - 1, m1, m2;
        while (lo < hi) {
            m1 = lo + (hi-lo)/2;
            m2 = m1 + 1;
            if (A[m1] > A[m2]) hi = m1;
            else lo = m2;
        }
	    return lo;
    }
};

void test1() {
    int arr[] = {8,9,1,2,3,4,5,6,7};
    //             1
    vector<int> v(arr, arr+9);
    cout << Solution::findPeak0(v) << ": ";
    cout << Solution::findPeak2(v) << ": ";
    cout << Solution::findPeak3(v) << endl;
}
void test2() {
    int arr[] = {4,10,9,8,7,6,5};
    //             1
    vector<int> v(arr, arr+7);
    cout << Solution::findPeak0(v) << ": ";
    cout << Solution::findPeak1(v) << ": ";
    cout << Solution::findPeak3(v) << endl;
}
void test3() {
    vector<int> v{1,2};
    cout << Solution::findPeak0(v) << ": ";
    cout << Solution::findPeak1(v) << ": ";
    cout << Solution::findPeak3(v) << endl;
}
int main(void) {
    test1();
    test2();
    test3();
    return 0;
}


