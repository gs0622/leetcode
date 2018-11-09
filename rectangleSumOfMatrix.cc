#include <iomanip>
#include <iostream>
using namespace std;
class myMatrix {
private:
    int *arr, *sum;
    int n;
    int idx(int r, int c) {
        return r * n + c;
    }
    void calculateSum(void) {
        int i, j;
        sum[0] = arr[0];
        for (i = 1; i < n; i++) {
            sum[idx(0, i)] = sum[idx(0, i-1)] + arr[idx(0, i)];
            sum[idx(i, 0)] = sum[idx(i-1, 0)] + arr[idx(i, 0)];
        }
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                sum[idx(i, j)] = sum[idx(i-1, j)] + sum[idx(i, j-1)] - sum[idx(i-1, j-1)];
            }
        }
    }
public:
    myMatrix(int sz) {
        int i, j;
        n = sz;
        arr = new int[n*n];
        sum = new int[n*n];
        for (i = 0; i < n*n; i++) arr[i] = i;
        calculateSum();
    }
    ~myMatrix() {
        delete arr;
        delete sum;
    }
    int querySum(int r, int c) {
        return sum[idx(r, c)];
    }
    int queryArr(int r, int c) {
        return arr[idx(r, c)];
    }
    void update(int r, int c, int v) {
        arr[idx(r, c)] = v;
        calculateSum();
    }

};
int main(void) {
    myMatrix m(5);
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cout << std::setw(3) << m.queryArr(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cout << std::setw(3) << m.querySum(i, j) << " ";
        }
        cout << endl;
    }
    m.update(0, 0, 1);
    cout << endl;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cout << std::setw(3) << m.querySum(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
