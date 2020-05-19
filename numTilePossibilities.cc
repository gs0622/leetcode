/* https://leetcode.com/problems/letter-tile-possibilities/description/
You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

Example 1:
Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: "AAABBC"
Output: 188
 
Note:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numTilePossibilities(string tiles) {
    int cnt[26]={};
    for (auto c: tiles) ++cnt[c-'A'];

    function<int(void)> helper=[&](void) {
      int sum=0;
      for (int i=0; i<26; ++i) {
        if (cnt[i]==0) continue;
        if (cnt[i]>0) {
          --cnt[i], ++sum;
          sum += helper();
          ++cnt[i];
        }
      }
      return sum;
    };

    return helper();
  }
};
int main(){
  Solution s;
  cout << s.numTilePossibilities("AAB") << endl;
  cout << s.numTilePossibilities("AAABBC") << endl;
}
