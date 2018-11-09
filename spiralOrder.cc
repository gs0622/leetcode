#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i, m, n, row, col;
        vector<int> r;
        m = matrix.size();
        if (m == 0) return r;
        n = matrix[0].size();
        row = 0; col = -1;
        while (true) {
            for (i = 0; i < n; i++)
                r.push_back(matrix[row][++col]);
            if (--m == 0) break;

            for (i = 0; i < m; i++)
                r.push_back(matrix[++row][col]);
            if (--n == 0) break;

            for (i = 0; i < n; i++)
                r.push_back(matrix[row][--col]);
            if (--m == 0) break;

            for (i = 0; i < m; i++)
                r.push_back(matrix[--row][col]);
            if (--n == 0) break;
        }
        return r;
    }
};

int main() {
    int a0[] = {1, 2, 3};
    int a1[] = {4, 5, 6};
    int a2[] = {7, 8, 9};
    vector<int> v0(a0, a0+3);
    vector<int> v1(a1, a1+3);
    vector<int> v2(a2, a2+3);
    vector<vector<int> > matrix;
    matrix.push_back(v0);
    matrix.push_back(v1);
    matrix.push_back(v2);
    Solution s;
    vector<int> r = s.spiralOrder(matrix);
    for (auto x: r) cout << x;
    cout << endl;
    return 0;
}
