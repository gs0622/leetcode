#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int bitwiseComplement(int n) {
    if (n==0) return 1;
    int pow=1;
    while (pow <= n)
      pow<<=1;
    return pow-n-1;
  }
};
int main(){
  Solution s;
  cout << s.bitwiseComplement(0) << endl;
  cout << s.bitwiseComplement(1) << endl;
  cout << s.bitwiseComplement(5) << endl;
  cout << s.bitwiseComplement(7) << endl;
  cout << s.bitwiseComplement(10) << endl;
  cout << s.bitwiseComplement(1000000000) << endl;
}
