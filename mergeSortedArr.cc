/*
https://leetcode.com/problems/merge-sorted-array/#/description

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n)
to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (j >= 0) // i might underflow.
            nums1[k--] = i >= 0 && (nums1[i] < nums2[j])? nums2[j--]: nums1[i--];
    }
};

int main(void) {
    int a[] = {0, 1, 2, 3, 0, 0, 0};
    int b[] = {1, 2, 5, 6};
    vector<int> va(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> vb(b, b+sizeof(b)/sizeof(b[0]));
    va.reserve(va.size()+vb.size());
    Solution s;
    s.merge(va, 0, vb, 1);
    for (auto x: va) cout << x << " ";
    cout << endl;
    return 0;
}
