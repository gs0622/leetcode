/*
see thru the data
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // O(n^2) time
  vector<string> invalidTransactions(vector<string>& T) { // {{name,time,amount,city}}
    int n=T.size();
    vector<string> res;
    unordered_map<string,map<int,pair<string,int>>> mp; // {name,{time,{city,idx}}
    vector<bool> tag(n,false);
    for (int i=0;i<n;i++) {
      istringstream is(T[i]);
      string name,city,amount,time;
      getline(is,name,','), getline(is,time,','), getline(is,amount,','), getline(is,city,',');
      if (stoi(amount)>1000)
        tag[i]=true;
      if (mp.count(name)) {
        int iTime=stoi(time);
        for (auto it=mp[name].begin();it!=mp[name].end();++it) {  // think why it has to brute-force here
          if (city!=it->second.first && abs(iTime-(it->first))<=60)
            tag[i]=true, tag[it->second.second]=true;
        }
      }
      mp[name][stoi(time)]={city,i};
    }
    for (int i=0;i<n;i++)
      if (tag[i]==true) res.push_back(T[i]);
    return res;
  }
};
int main(){
  Solution s;
  //vector<string> T0{"bob,689,1910,barcelona","alex,696,122,bangkok","bob,832,1726,barcelona","bob,820,596,bangkok","chalicefy,217,669,barcelona","bob,175,221,amsterdam"};
  //vector<string> T0{"bob,627,1973,amsterdam","alex,387,885,bangkok","alex,355,1029,barcelona","alex,587,402,bangkok","chalicefy,973,830,barcelona","alex,932,86,bangkok","bob,188,989,amsterdam"};
  vector<string> T0{"chalicefy,639,1283,beijing","maybe,324,192,frankfurt","bob,627,974,amsterdam","alex,962,125,chicago","iris,849,36,beijing","chalicefy,70,415,bangkok","chalicefy,112,467,frankfurt","xnova,358,82,barcelona","chalicefy,180,543,beijing","xnova,624,572,budapest","lee,651,1761,chicago","alex,991,1698,budapest","bob,531,700,amsterdam","chalicefy,926,478,budapest","iris,235,1993,frankfurt","alex,107,812,beijing","maybe,199,1313,barcelona"};
  for (auto t: s.invalidTransactions(T0)) cout << t << ",";
  cout << endl;
  vector<string> T1{"alice,80,800,mtv","alice,20,100,beijing"};
  for (auto t: s.invalidTransactions(T1)) cout << t << ",";
  cout << endl;
  vector<string> T2{"alice,20,800,mtv","alice,50,1200,mtv"};
  for (auto t: s.invalidTransactions(T2)) cout << t << ",";
  cout << endl;
  vector<string> T3{"alice,20,800,mtv","bob,50,1200,mtv"};
  for (auto t: s.invalidTransactions(T3)) cout << t << ",";
  cout << endl;
}
