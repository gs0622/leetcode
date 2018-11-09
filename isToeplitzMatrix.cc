#include <iostream>
using namespace std;
int idx(int r, int c, int w) {
    return r * w + c;
}
int _check(int arr[], int i, int j, int r, int c) {
    int ii, jj;
    int v = arr[idx(i, j, c)];
    for (ii = i+1, jj = j+1; ii < r && jj < c; ii+=1, jj+=1) {
        if (v != arr[idx(ii, jj, c)]) return 0;
    }
    return 1;
}
int check(int arr[], int r, int c) {
        int i, j;
        int yesno = 1;
        for (i = 0; i < c; i++) yesno &= _check(arr, i, 0, r, c);
        for (i = 1; i < r; i++) yesno &= _check(arr, 0, i, r, c);
        return yesno;
}
int main(void) {
    int arr[25] = {
        1,2,3,4,5,
        6,1,2,3,4,
        7,6,1,2,3,
        8,7,6,1,2,
        9,8,7,6,1
    };
    cout << check(arr, 3, 5) << endl;
    return 0;
}
