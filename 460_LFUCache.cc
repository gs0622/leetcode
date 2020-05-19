/*
https://leetcode.com/problems/lfu-cache/description/
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item.
For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?
*/
#include <bits/stdc++.h>
using namespace std;
class LFUCache {
  int cap, min;
  unordered_map<int,pair<int,int>> mp;          // {key: {val: cnt}}
  unordered_map<int,list<int>::iterator> ir;    // {key: iterator}
  unordered_map<int,list<int>> fr;              // {freq: [key]}
public:
  LFUCache(int capacity) { cap=capacity; }
  int get(int key) {
    if (!cap || !mp.count(key)) return -1;      // no cap or no key
    auto& p = mp[key];
    fr[p.second++].erase(ir[key]);              // erase fr by ir[key]
    fr[p.second].push_front(key);               // push ket into front at fr
    ir[key]=fr[p.second].begin();               // update ir[key]
    if (fr[min].empty()) ++min;                 // update min-freq
    return p.first;
  }
  void put(int key, int val) {
      if (!cap) return;
      if (get(key)!=-1) {                       // fr has been updated in return
        mp[key].first=val;                      // if key exist, fix the val
        return;
      }
      if (mp.size()>=cap) {                     // evict in case capping
        auto key = fr[min].back();              // least recent use
        mp.erase(key), ir.erase(key), fr[min].pop_back();
      }
      mp[key]={val,1}, fr[1].push_front(key), ir[key]=fr[1].begin();
      min=1;
  }
};
int test1(){
  LFUCache cache( 2 /* capacity */ );
  cache.put(1, 1);                  // {{1,1}}
  cache.put(2, 2);                  // {{1,1},{2,2}}
  cout << cache.get(1) << endl;     // returns 1
  cache.put(3, 3);                  // evicts key 2, {{1,1},{3,3}}
  cout << cache.get(2) << endl;     // returns -1 (not found)
  cout << cache.get(3) << endl;     // returns 3.
  cache.put(4, 4);                  // evicts key 1.
  cout << cache.get(1) << endl;     // returns -1 (not found)
  cout << cache.get(3) << endl;     // returns 3
  cout << cache.get(4) << endl;     // returns 4
}
int test2(){
  LFUCache cache( 2 /* capacity */ );
  cache.put(1, 1);                  // {{1,1}}
  cache.put(2, 2);                  // {{1,1},{2,2}}
  cout << cache.get(1) << endl;     // returns 1
  cache.put(3, 3);                  // evicts key 2, {{1,1},{3,3}}
  cout << cache.get(2) << endl;     // returns -1 (not found)
  cout << cache.get(3) << endl;     // returns 3.
}
int test3(){
  LFUCache cache( 1 /* capacity */ );
  cache.put(2, 1);
  cout << cache.get(2) << endl;
  cache.put(3, 2);
  cout << cache.get(2) << endl;
  cout << cache.get(3) << endl;
}
int test4(){
  LFUCache c(10);
  c.put(10, 13),c.put(3,17),c.put(6,11),c.put(10,5),c.put(9,10);
  cout << c.get(13) << endl;
  c.put(2,19);
  cout << c.get(2) << endl;
  cout << c.get(3) << endl;
  c.put(5,25);
  cout << c.get(8) << endl;
  c.put(9,22),c.put(5,5),c.put(1,30);
  cout << c.get(11) << endl;
  c.put(9,12);
  cout << c.get(7) << endl;
  cout << c.get(5) << endl;
  cout << c.get(8) << endl;
  cout << c.get(9) << endl;
  c.put(4,30),c.put(9,3);
  cout << c.get(9) << endl;
  cout << c.get(10) << endl;
  cout << c.get(10) << endl;
  c.put(6,14),c.put(3,1);
  cout << c.get(3) << endl;
  c.put(10,11);
  cout << c.get(8) << endl;
  c.put(8,14);
  cout << c.get(1) << endl;
  cout << c.get(5) << endl;
  cout << c.get(4) << endl;
  // [11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]
  c.put(11,4),c.put(12,24),c.put(5,18);
  cout << c.get(13) << endl;
  c.put(7,23);
  cout << c.get(8) << endl;
  cout << c.get(12) << endl;
  c.put(3,27),c.put(2,12);
  cout << c.get(5) << endl;
  c.put(2,9),c.put(13,4),c.put(8,18),c.put(1,7);
  cout << c.get(6) << endl;
  
}
int main(){
  test4();
}

