#include <bits/stdc++.h>
using namespace std;
class ProductOfNumbers { 
  vector<int> pre{1};
public:
  void add(int num) {
    if (num!=0) pre.push_back(pre.back()*num);
    else pre={1};
  }
  int getProduct(int k) {
    if (k>=pre.size()) return 0;
    return pre.back()/pre[pre.size()-k-1];
  }
};

class ProductOfNumbers2 { 
  vector<int> lst;
public:
  ProductOfNumbers() {
  }
  void add(int num) {
    lst.push_back(num);
  }
  int getProduct(int k) {
    int n=lst.size(),res=1;
    for (int i=n-1;i>n-k-1;--i)
      res*=lst[i];
    return res;
  }
};

int main(){}
