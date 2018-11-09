/* https://leetcode.com/problems/fruit-into-baskets/description/

In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?


Problem
"Start from any index, we can collect at most two types of fruits. What is the maximum amount"

Translation
Find out the longest length of subarrays with at most 2 different numbers?

Solution of sliding window will be easier to understand.
Here I share another solution wihtout hash map.
Hope it's not damn hard to understand.

aabbbc
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int totalFruit1(vector<int>& T) {
		int res=0, cur=0, cnt_b=0, a=0, b=0;
		for (auto c: T) {
			cur = (c==a||c==b)? cur+1: cnt_b+1;
			cnt_b = (c==b)? cnt_b+1: 1;
			if (b!=c) a=b, b=c;
			res = max(res, cur);
		}
		return res;
	}
	int totalFruit(vector<int>& T) {
		unordered_map<int,int> mp;
		int res=0;
		for (int i=0, j=0; j<T.size(); ++j) {	// j: tree-per-tree, i: left window start
			++mp[T[j]];
			while (mp.size()>2) {	// e.g., 1,2,1,1,2 -> 1,2,1,1,2,3 -> 3
				--mp[T[i]];
				if (mp[T[i]]==0) mp.erase(T[i]);
				++i;
			}
			res=max(res, j-i+1);
		}
		return res;
	}
};
int main(){
	Solution s;
	vector<int> T1{1,2,1};
	cout << s.totalFruit(T1) << endl;
	vector<int> T2{0,1,1,2};
	cout << s.totalFruit(T2) << endl;
	vector<int> T4{3,3,3,1,2,1,1,2,3,3,4};
	cout << s.totalFruit(T4) << endl;
}
