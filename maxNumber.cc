#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        std::priority_queue<int, std::vector<int>, std::less<int> > pq;
        std::vector<int> r;
        for (auto x: nums1) pq.push(x);       
        for (auto y: nums2) pq.push(y);
        for (int i = k; i > 0; i--) {
            cout << pq.top() << endl;
            r.push_back(pq.top());
            pq.pop();
        }
        return r;
    }
};

int main() {
    int n1[] = {3,4,6,5};
    int n2[] = {9,1,2,5,8,3};
    vector<int> v1(n1, n1+4);
    vector<int> v2(n2, n2+5);
    Solution s;
    vector<int> r = s.maxNumber(v1, v2, 5);
    for (auto x: r)
        cout << x << " ";
    cout << endl;
    return 0;
}
