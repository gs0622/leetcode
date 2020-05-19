/* https://leetcode.com/problems/find-common-characters/description/

Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Note:
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  // O(n)
  vector<string> commonChars(vector<string>& A) {
    int n=A.size();
    vector<int> gCnt(26,INT_MAX);
    for (int i=0; i<n; ++i) {
      vector<int> tCnt(26,0);
      for (int j=0; j<A[i].size(); ++j)
        tCnt[A[i][j]-'a']+=1;
      for (int j=0; j<26; ++j)
        gCnt[j]=min(gCnt[j],tCnt[j]);
    }
    vector<string> res;
    for (int i=0; i<26; ++i) {
      if (gCnt[i]>0) {
        for (int j=0; j<gCnt[i]; ++j)
          res.push_back(string(1,('a'+i)));
      }
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<string> A1{"bella","label","roller"};
  for (auto s: s.commonChars(A1)) cout << s << " ";
  cout << endl;
}
