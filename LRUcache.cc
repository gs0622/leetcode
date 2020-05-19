/*
  https://leetcode.com/problems/lru-cache/description/

  Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

  get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
  put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

  Follow up:
  Could you do both operations in O(1) time complexity?
 */
#include <bits/stdc++.h>
using namespace std;
class LRUCache2 {
  list<pair<int,int>> dq;   // {key: val}
  int cap;
public:
  LRUCache2(int capicity) { cap = capicity; }
  int get(int key) {
    auto it=find_if(dq.begin(), dq.end(), [&](pair<int,int> p){ return p.first==key; } );  // O(n)
    if (it==dq.end()) return -1;    // no, return not found
    auto p = *it;                   // pair of {key: val}
    dq.erase(it);                   // remove old entry
    dq.push_front(p);               // enqueue new to the front
    return p.second;                // return val
  }
  void put(int key, int val) {
      if (get(key)==-1) {           // O(n)
        if (dq.size()==cap)         // evict in LRU policy
          dq.pop_back();
        dq.emplace_front(key,val);
      } else {                      // exist
        dq.begin()->second = val;
      }
  }
};
class LRUCache1 {
  list<pair<int,int>> dq; // {key,val}
  unordered_map<int,list<pair<int,int>>::iterator> mp;  // {key: iterator}
  int cap;
public:
  LRUCache1(int capicity) { cap = capicity; }
  int get(int key) {
      if (!mp.count(key)) return -1;    // O(1) time
      auto it = mp[key];                // O(1) time
      auto p = *it;
      dq.erase(it);
      dq.push_front(p);
      mp[key]=dq.begin();
      return p.second;
  }
  void put(int key, int val) {
      if (get(key)!=-1) {
        dq.front().second = val;
        return;
      }
      if (dq.size()==cap) {
        mp.erase(dq.back().first);
        dq.pop_back();
      }
      dq.emplace_front(key,val);
      mp[key]=dq.begin();
  }
};
class LRUCache {
	unordered_map<int,pair<int,list<int>::iterator>> mp;	// {key: {val, iterator}} 
	list<int> dq;						// {key}
	int cap;
public:
	LRUCache(int capacity) { cap = capacity; }
	int get(int key) {
		if (mp.count(key) == 0)
			return -1;
		auto p = mp[key];               // p = {val, iterator}
		dq.erase(p.second);             // O(1) evict dq iterator
		dq.push_front(key);             // O(1) add to head
		mp[key]={p.first, dq.begin()};  // update {key: {val, iterator}}
		return p.first;                 // return val
	}
	void put(int key, int val) {
		if (dq.size() < cap || mp.count(key)) {
			if (mp.count(key))
				dq.erase(mp[key].second);
		} else {
			mp.erase(dq.back());
			dq.pop_back();
		}
		dq.push_front(key);
		mp[key]={val,dq.begin()};
	}
};
void test1(){
	LRUCache cache(2);
	cache.put(2,1);
	cache.put(2,2);
	cout << cache.get(2) << endl;
	cache.put(1, 1);
	cache.put(4, 1);
	cout << cache.get(2) << endl;
}
void test2(){
	LRUCache1 c(10);
	c.put(10,13);
	c.put(3,17);
	c.put(6,11);
	c.put(10,5);
	c.put(9,10);
	cout << c.get(13) << endl;
	c.put(2,19);
	cout << c.get(2) << endl;
	cout << c.get(3) << endl;
	c.put(5,25);
	cout << c.get(8) << endl;
	c.put(9,22);
	c.put(5,5);
	c.put(1,30);
	cout << c.get(11) << endl;
	c.put(9,12);
	cout << c.get(5) << endl;
	cout << c.get(7) << endl;
	cout << c.get(8) << endl;
	cout << c.get(9) << endl;
	c.put(4,30);
	c.put(9,3);
	cout << c.get(9) << endl;
	cout << c.get(10) << endl;
	cout << c.get(10) << endl;
	c.put(6,14);
	c.put(3,1);
	cout << c.get(3) << endl;
	c.put(10,11);
	cout << c.get(8) << endl;
	c.put(2,14);
	cout << c.get(1) << endl;
	cout << c.get(5) << endl;
	cout << c.get(4) << endl;
	c.put(11,4);
	c.put(12,24);
	c.put(5,18);
	cout << c.get(13) << endl;
	c.put(7,23);
	cout << c.get(8) << endl;
	cout << c.get(12) << endl;
	c.put(3,27);
	c.put(2,12);
	cout << c.get(5) << endl;
	c.put(2,9);
	c.put(13,4);
	c.put(8,18);
	c.put(1,7);
	cout << c.get(6) << endl;
	c.put(9,29);
	c.put(8,21);
	cout << c.get(5) << endl;
	c.put(6,30);
	c.put(1,12);
	cout << c.get(10) << endl;
	c.put(4,15);
	c.put(7,22);
	c.put(11,26);
	c.put(8,17);
	c.put(9,29);
	cout << c.get(5) << endl;
} 
void test3(){
	LRUCache cache(2);
	cache.put(1,1);
	cache.put(1,2);
	cout << cache.get(1) << endl;
	cache.put(3,3);
	cout << cache.get(2) << endl;
	cache.put(4,4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
}
void test4(){
	LRUCache2 cache(2);
	cout << cache.get(2) << endl;
	cache.put(2,6);
	cout << cache.get(1) << endl;
	cache.put(1,5);
	cache.put(1,2);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
}
int main() {
	//test1();
	test2();
	//test3();
	//test4();
}
