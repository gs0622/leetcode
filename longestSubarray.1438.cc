#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int longestSubarray(vector<int>& A, int L) {
    int n=A.size(),res=0;
    multiset<int> st;
    for (int i=0,j=0;j<n;++j) {
      st.insert(A[j]);
      while (*st.rbegin()-*st.begin()>L)
        st.erase(A[i++]);
      res=max(res,j-i+1);
    }
    return res;
  }
};
class Solution3 {
public:
  int longestSubarray(vector<int>& A, int L) {
    deque<int> dec,inc;
    int n=A.size(),res=0;
    for (int i=0,j=0;j<n;++j) {
      while (dec.size() && dec.back()<A[j])       // 8,2
        dec.pop_back(); // monotonic dec, max q
      while (inc.size() && inc.back()>A[j])       // 8 -> 2
        inc.pop_back(); // monotonic inc, min q
      dec.push_back(A[j]);
      inc.push_back(A[j]);
      if (abs(dec.front()-inc.front())>L) {
        if (A[i]==dec.front()) dec.pop_front();
        if (A[i]==inc.front()) inc.pop_front();
        ++i;
      }
      res=max(res,j-i+1);
    }
    return res;
  }
};
class Solution2 {
public:
  int longestSubarray(vector<int>& A, int L) {
    int n=A.size(),res=0;
    priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>> maxheap;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
    for (int i=0,j=0;i<n;++i) { // nlogn
      maxheap.push({A[i],i});   // 8,2
      minheap.push({A[i],i});   // 2,8
      while (maxheap.top()[0]-minheap.top()[0]>L) {   // [8,0],[2,1]
        j=min(maxheap.top()[1],minheap.top()[1])+1;   // 0
        while (maxheap.top()[1]<j)
          maxheap.pop();
        while (minheap.top()[1]<j)
          minheap.pop();
      }
      res=max(res,i-j+1);
    }
    return res;
  }
};
class Solution1 {
public: // TLE, 53/54
  int longestSubarray(vector<int>& A, int L) {
    int n=A.size(),res=1,mi=A[0],mx=A[0];
    for (int i=1,j=0;i<=n;++i) {
      mi=*min_element(A.begin()+j,A.begin()+i);
      mx=*max_element(A.begin()+j,A.begin()+i);
      while (mx-mi>L && j<i) {
        ++j;
        mi=*min_element(A.begin()+j,A.begin()+i);
        mx=*max_element(A.begin()+j,A.begin()+i);
        
      }
      res=max(res,i-j);
    }
    return res;
  }
};
int main(){
  Solution s;
  vector<int> A1{8,2,4,7};
  cout << s.longestSubarray(A1,4) << endl;
  //vector<int> A1{2,5,2};
  //cout << s.longestSubarray(A1,9) << endl;
}
