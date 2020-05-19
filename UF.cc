#include <bits/stdc++.h>
using namespace std;

class UF {
  unordered_map<int,int> id;
  int find(int p) {
    while (p!=id[p]) p=id[p];
    return p;
  }
  public:
  UF(int n=10) {
    for (int i=0;i<n;i++) id[i] = i;
  }
  void Union(int p, int q)
  {
    int rp = find(p), rq = find(q);
    if (rp!=rq) id[rp] = rq;
  }
  int groups() {
    unordered_set<int> s;
    for (int i=0; i<id.size(); ++i)
      s.insert(find(i));
      return s.size();
  }
  void Trace(void)
  {
    for (int i=0;i<(int)id.size();i++) cout << id[i] << " ";
    cout << endl;
  }
};

int main(void)
{
  UF u1(10);
    u1.Trace();
    u1.Union(1, 0);
    u1.Trace();
    cout << u1.groups() << endl;
    return 0;
}

