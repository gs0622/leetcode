#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string defangIPaddr(string address) {
    return regex_replace(address,regex("[.]"),"[.]");
  }
};
int main(){
  Solution s;
  cout << s.defangIPaddr("1.1.1.1") << endl;
}
