#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution2 {
public:
  vector<int> findMode(TreeNode* root) {
    map<int,int> mp;
    function<void(TreeNode*)> helper=[&](TreeNode* cur) {
      if (!cur) return;
      helper(cur->left);
      ++mp[cur->val];
      helper(cur->right);
    };
    helper(root);
    priority_queue<vector<int>,vector<vector<int>>, less<vector<int>>> pq;  // maxheap
    for (auto p: mp)
      pq.push({p.second, p.first}); // {cnt, val}
    auto p = pq.top(); pq.pop();
    vector<int> res(1, p[1]);
    while (pq.top()[0] == p[0])
      res.push_back(pq.top()[1]), pq.pop();

    return res;
  }
};
class Solution {
public:
  vector<int> findMode(TreeNode* root) {
    stack<TreeNode*> s;
    unordered_map<int,int> mp;  // {key: cnt} map
    TreeNode *cur=root;
    while (cur || s.size()) {
      while (cur)
        s.push(cur), cur=cur->left;
      cur=s.top(), s.pop();
      ++mp[cur->val]; // visit
      cur=cur->right;
    }
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;  // minheap
    int cnt=0;
    for (auto p: mp) {
      pq.push({p.second,p.first}), cnt=max(cnt,p.second);   // {cnt: key} priority queue
      while (pq.top()[0]<cnt)
        pq.pop();
    }
    vector<int> res;
    while (pq.size())
      res.push_back(pq.top()[1]), pq.pop();
    return res;
  }
};
int main(){
  TreeNode n3(2), n2(2), n1(INT_MIN);
  //n1.right=&n2, n2.left=&n3;
  Solution2 s;
  for (auto n: s.findMode(&n1))
    cout << n << endl;
}
