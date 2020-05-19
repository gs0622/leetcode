/*
We are given an elevation map, heights[i] representing the height of the terrain at that index. The width at each index is 1. After V units of water fall at index K, how much water is at each index?
Water first drops at index K and rests on top of the highest terrain or water at that index. Then, it flows according to the following rules:
If the droplet would eventually fall by moving left, then move left.
Otherwise, if the droplet would eventually fall by moving right, then move right.
Otherwise, rise at it's current position.
Here, "eventually fall" means that the droplet will eventually be at a lower level if it moves in that direction. Also, "level" means the height of the terrain plus any water in that column.

We can assume there's infinitely high terrain on the two sides out of bounds of the array. Also, there could not be partial water being spread out evenly on more than 1 grid block - each unit of water has to be in exactly one block.
Example 1:
Input: heights = [2,1,1,2,1,2,2], V = 4, K = 3
Output: [2,2,2,3,2,2,2]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> pourWater(vector<int>& H, int V, int K) {
    int n=H.size(),L=K,R=K;
    for (int i=0;i<V;++i) {
      while (L>0 && H[L]>=H[L-1]) --L;
      while (L<K && H[L]==H[L+1]) ++L;
      while (R<n-1 && H[R]>=H[R+1]) ++R;
      while (R>K && H[R]==H[R-1]) --R;
      (H[L]<H[K])? ++H[L]: ++H[R];
    }
    return H;
  }
};
int main(){
  Solution s;
  vector<int> A1{2,1,1,2,1,2,2};  // V=4,K=3
  //            {2,2,2,3,2,2,2}
  for (auto n: s.pourWater(A1,4,3)) cout << n << " ";
  cout << endl;
}
