/* https://www.careercup.com/question?id=4601987345678336
Sort a list of numbers in which each number is at a distance k from its actual position
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> sortK(vector<int>& A,int k) {
    int n=A.size();
    for (int i=0;i<n-1-k;i+=2*k)    // base i, 
      for (int j=0;j<k;++j)
        swap(A[i+j],A[i+j+k]);
    return A;
  }
};
int main(){
  Solution s;
  vector<int> A1{3, 4, 1, 2, 7, 8, 5, 6};
  for (auto n: s.sortK(A1,2)) cout << n << " ";
  cout << endl;
}
