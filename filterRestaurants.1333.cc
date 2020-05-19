#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> filterRestaurants(vector<vector<int>>& A, int veganFriendly, int maxPrice, int maxDistance) {
    struct cmp {
      bool operator()(vector<int> a, vector<int> b) {
        return a[1]<b[1]||(a[1]==b[1]&&a[0]<b[0]);
      }
    };
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    for (auto a: A) {
      if (a[2]>=veganFriendly && a[3]<=maxPrice && a[4]<=maxDistance)
        pq.push(a);
    }
    vector<int> res;
    while (pq.size())
      res.push_back(pq.top()[0]),pq.pop();
    return res;
  }
};
class Solution3 {
public:
  vector<int> filterRestaurants(vector<vector<int>>& A, int veganFriendly, int maxPrice, int maxDistance) {
    function<bool(vector<int>, vector<int>)> helper=[&](vector<int> a, vector<int> b) {
      return a[1]>b[1]||(a[1]==b[1]&&a[0]>b[0]);
    };
    sort(A.begin(),A.end(),helper);
    vector<int> res;
    for (auto a: A) {
      if (a[2]>=veganFriendly && a[3]<=maxPrice && a[4]<=maxDistance)
        res.push_back(a[0]);
    }
    return res;
  }
};
class Solution2 {
public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    int n=restaurants.size();
    vector<vector<int>> A;
    for (int i=0;i<n;++i) {
      if (veganFriendly) {
        if (restaurants[i][2] && restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
          A.push_back(restaurants[i]);
      } else {
        if (restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
          A.push_back(restaurants[i]);
      }
    }
    function<bool(vector<int>, vector<int>)> helper=[&](vector<int> a, vector<int> b) {
      return a[1]>b[1]||(a[1]==b[1]&&a[0]>b[0]);
    };
    sort(A.begin(),A.end(),helper);
    vector<int> res;
    for (auto a: A)
      res.push_back(a[0]);
    return res;
  }
};
int main(){}
