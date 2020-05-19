#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> res(num_people);
    int left = candies;
    for (int i=0,k=1; left>0; i++) {
      if (left<k) {
        res[i%num_people]+=left;
        break;
      }
      res[i%num_people]+=k, left-=k, k++;
    }
    return res;
  }
};
int main(){
  Solution s;
  for (auto n: s.distributeCandies(7,4)) cout << n << " ";
  cout << endl;
  for (auto n: s.distributeCandies(10,3)) cout << n << " ";
  cout << endl;
}
