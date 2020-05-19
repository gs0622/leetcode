#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minCostToMoveChips(vector<int>& chips) {
    int odd, even;
    for (auto c: chips) (c%2)? ++odd: ++even;
    return min(odd,even); 
  }
};
int main(){
}
