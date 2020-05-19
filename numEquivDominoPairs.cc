/* https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.
Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

Example 1:
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
 
Constraints:
1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int,int> mp;
    int res=0;
    for (auto p: dominoes)
      res+=mp[min(p[0],p[1])*10+max(p[0],p[1])]++;  // 0 1 ...
    return res;
  }
};
class Solution {
public: // O(2n)
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int n=dominoes.size(), res=0;
    unordered_map<string,int> mp;
    for (int i=0;i<n;++i) {
      string key=(dominoes[i][0]<dominoes[i][1])?
        to_string(dominoes[i][0])+","+to_string(dominoes[i][1]):
        to_string(dominoes[i][1])+","+to_string(dominoes[i][0]);
      ++mp[key];
    }
    for (auto p: mp) {
      res+=p.second*(p.second-1)/2;
    }
    return res;
  }
};
int main(){
  Solution2 s;
  vector<vector<int>> A1{{1,2},{2,1},{3,4},{5,6}};
  cout << s.numEquivDominoPairs(A1) << endl;
  vector<vector<int>> A2{{1,1},{2,2},{1,1},{1,2},{1,2},{1,1}};
  cout << s.numEquivDominoPairs(A2) << endl;
}
