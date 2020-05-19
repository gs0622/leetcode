/* https://leetcode.com/problems/snapshot-array/description/
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5

hint: see thru the data: how to reduce the memory usage?
*/
#include <bits/stdc++.h>
using namespace std;
class SnapshotArray {
  int id;
  vector<vector<pair<int,int>>> A; // {index: {snap: val}}          // O(n) space
public:
  SnapshotArray(int length): id(0), A(length) {}
  int snap() { return id++; }
  void set(int index, int val) {
      if (A[index].empty() || A[index].back().first<id) A[index].push_back({id,val});
      else if (id==A[index].back().first) A[index].back().second = val;
      //if (A[index].empty() || A[index].back().first<id)
      //  A[index].push_back({id,val});
      //else if (id==A[index].back().first)
      //  A[index].back().second;
  }
  int get(int index, int snap_id) {
      if (A[index].empty()) return 0;
      auto it = find_if(A[index].begin(),A[index].end(), [&](pair<int,int> a){ return a.first>=snap_id;}); // O(n) time
      if (it==A[index].end()) return A[index].back().second;    // old set value
      else return it->second;
  }
};
class SnapshotArray4 {
  int id;
  vector<vector<pair<int,int>>> mp; // {index: {snap_id: val}};
public:
  SnapshotArray4(int length): id(0), mp(length) {}
  int snap() { return id++; }
  void set(int index, int val) {
    if (mp[index].empty()||mp[index].back().first<id)
      mp[index].emplace_back(id,val);
    else
      mp[index].back().second=val;
  }
  int get(int index, int snap_id) {
    if (mp[index].empty()) return 0;
    auto it=lower_bound(mp[index].begin(),mp[index].end(),make_pair(snap_id,0),
      [](pair<int,int> a, pair<int,int> b){ return a.first<b.first; });
    if (it==mp[index].end()) return mp[index].back().second;  // no snapshot, must be old one
    if (it->first==snap_id) return it->second;  // target is equal to
    if (it==mp[index].begin()) return 0;        // target is less than, no snapshot
    return it[-1].second;                       // target is less than, has snapshot
  }
};
class SnapshotArray3 {
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
  int id;
  vvvi mp; // {index: {snap_id: val}};
public:
  SnapshotArray3(int length): id(0), mp(length) {}
  void set(int index, int val) {
    if (mp[index].empty())
      mp[index].push_back({id,val});
    else if (mp[index].back()[0]<id)
      mp[index].push_back({id,val});
    else
      mp[index].back()[1]=val;
  }
  int snap() { return id++; }
  int get(int index, int snap_id) {
    if (mp[index].empty())
      return 0;
    auto it = lower_bound(mp[index].begin(),mp[index].end(),vi{snap_id,0},[](vi L, vi R){return L[0]<R[0];});
    if (it==mp[index].end())
      return mp[index].back()[1];
    if (it[0][0]==snap_id)
      return it[0][1];
    if (it==mp[index].begin())  // less
      return 0;
    return it[-1][1];
  }
};
class SnapshotArray1 {
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
  int id;
  vvvi mp; // {index: {snap_id: val}};
public:
  SnapshotArray1(int length): id(0), mp(length) {}
  void set(int index, int val) {
    if (mp[index].empty())
      mp[index].push_back({id,val});
    else if (mp[index].back()[0]<id)
      mp[index].push_back({id,val});
    else
      mp[index].back()[1]=val;
  }
  int snap() { return id++; }
  int get(int index, int snap_id) {
    if (mp[index].empty())
      return 0;
    auto it = lower_bound(mp[index].begin(),mp[index].end(),vi{snap_id,0},[](vi L, vi R){return L[0]<R[0];});
    if (it==mp[index].end())
      return mp[index].back()[1];
    //if (it[0][0]==snap_id)
    //  return it[0][1];
    if (it==mp[index].begin())
      return 0;
    if (it[0][0]==snap_id)
      return it[0][1];
    else
      return it[-1][1];
  }
};

class SnapshotArray2 { // MLE
  int id;
  vector<int> nums;
  unordered_map<int,vector<int>> mp;  // naive one
public:
  SnapshotArray2(int length) {
    nums.resize(length,0);
    id=0;
    mp.clear();
  }
  void set(int index, int val) {
    nums[index]=val;
  }
  int snap() {
    mp[id++]=nums;
    return id-1;
  }
  int get(int index, int snap_id) {
    return mp[snap_id][index];
  }
};

int main(){
  SnapshotArray s(1);
  s.set(0,15);
  cout << s.snap() << endl;
  cout << s.snap() << endl;
  cout << s.snap() << endl;
  cout << s.get(0,2) << endl;
  cout << s.snap() << endl;
  cout << s.snap() << endl;
  cout << s.get(0,0) << endl;
}
