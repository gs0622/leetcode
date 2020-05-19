/*
https://leetcode.com/problems/unique-binary-search-trees/description/
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
hint:
G(n): the number of unique BST for a sequence of length n.
F(i, n), 1 <= i <= n: the number of unique BST, where the number i is the root of BST, and the sequence ranges from 1 to n.
G(n) = F(1, n) + F(2, n) + ... + F(n, n)
G(0)=1, G(1)=1
F(i, n) = G(i-1) * G(n-i)	1 <= i <= n 
(G[j,i]=G[j-1]*G[i-j])
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  int numTrees(int n) {
    vector<int> G(n+1);
    G[0]=G[1]=1;  // 0: empty, 1: 1 only
    for (int i=2;i<=n;++i)
      for (int j=1;j<=i;++j)
        G[i]+=G[j-1]*G[i-j];
    return G[n];
  }
};
int main(){}
