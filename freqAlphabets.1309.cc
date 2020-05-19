#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string freqAlphabets(string s) {
    int n=s.size();
    string res;
    for (int i=0;i<n;++i) {
      if (i<n-2 && s[i+2]=='#')
        res+='j'+(s[i]-'0')*10+(s[i+1]-'0')-10, i+=2;
      else
        res+='a'+s[i]-'1';
    }
    return res;
  }
};
int main(){
  Solution s;
  cout << s.freqAlphabets("10#11#12") << endl;
  cout << s.freqAlphabets("1326#") << endl;
}
