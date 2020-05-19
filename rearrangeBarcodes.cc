/*
https://leetcode.com/problems/distant-barcodes/description/
In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].
Rearrange the barcodes so that no two adjacent barcodes are equal.
You may return any answer, and it is guaranteed an answer exists.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    int n=barcodes.size();
    unordered_map<int,int> cnt;
    for (auto b: barcodes) ++cnt[b];                    // O(n) time {key, cnt}

    priority_queue<pair<int,int>> pq;
    for (auto it: cnt) pq.push({it.second, it.first});  // O(nlogn) time {cnt,key}

    vector<int> res(n);
    int odd=0,even=1;
    while (pq.size()) {
      auto p=pq.top(); pq.pop();
      while (odd<n && p.first>0)
        res[odd]=p.second, odd+=2, p.first--;
      while (even<n && p.first>0)
        res[even]=p.second, even+=2, p.first--;
    }

    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,1,1,1,2,2,3,3};
  for (auto n: s.rearrangeBarcodes(A1))
    cout << n << " ";
  cout << endl;
}
