#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int longestStrChain(vector<string>& words) {
    int n=words.size(),res=0;
    sort(words.begin(),words.end(),[](string a, string b){return a.size()<b.size();});  // O(nlogn)
    unordered_map<string,int> mp;
    for (auto w: words) {
      int best=0;
      for (int i=0;i<w.size();++i) {  // loop for missing char
        string pre=w.substr(0,i)+w.substr(i+1);
        best=max(best,mp[pre]+1);
      }
      mp[w]=best, res=max(res,best);
    }
    return res;
  }
};
int main(){
}
