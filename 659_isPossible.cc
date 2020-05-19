/*
https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106493/C++-O(n)-solution-two-pass

You are given an integer array sorted in ascending order (may contain duplicates),
you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Q: what about one subsequence only? remain true?

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
*/
#include <bits/stdc++.h>
using namespace std;
/*
The idea is , we scan the array for two times.
In first pass we count the frequencies of all numbers and record them in cnt
For the second pass, we are "building" our subsequences by the following rules:

We use a hashmap called tails to record extra information, where tails[i] means the number of consecutive subsequences we've found so far, who are longer than 3 , and tailed by number i,
When we meet number i, try to put it to the tail of one of found subsequences tailed by i-1. No need to worry that we might have a better choice to consider i as a brand new head for another subsequence, because we can always append the new subsequence to a previous one tailed by i-1.
If we can't, it will cost one i+1 and one i+2 later to generate a new sequence. We just pay that right now by decrease cnt[i+1] and cnt[i+2]. Some one may worry that we make use of the numbers we haven't scanned so far. But actually we've already kept track of the numbers remained by cnt. Just imaging we grab the numbers needed from the very end of the string, and mark them as "used". If there is no such number available to pay, cnt will tell us by checking cnt[i+1] cnt[i+2] is positive or not
*/
class Solution {
public:
  bool isPossible(vector<int>& nums) {  // O(n) w/ two-pass
    unordered_map<int,int> cnt, tail;
    for (auto n: nums) ++cnt[n];
    for (auto n: nums) {        // sorted and ascending
      if (cnt[n]==0) continue;  // n has been used
      --cnt[n];                 // mark n as used
      if (tail[n-1] > 0)        // greedy: track it to the tail of one of found subsequences tailed by i-1
        --tail[n-1], ++tail[n];
      else if (cnt[n+1]>0 && cnt[n+2]>0)
        --cnt[n+1], --cnt[n+2], ++tail[n+2];
      else
        return false;
    }
    return true;
  }
};
int main(){
  Solution s;
  vector<int> A1{1,2,3,3,4,5};
  cout << s.isPossible(A1) << endl;
  vector<int> A2{1,2,3,5,6};
  cout << s.isPossible(A2) << endl;
  vector<int> A3{5,6,7,25,26,27,28,29,30,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,40,41,41,41,42,42,42,43,43,43,44,44,44,45,45,45,46,46,47,47,47,48,48,48,49,49,49,50,50,50,51,51,51,52,52,52,53,53,53,54,54,54,55,55,55,56,56,56,57,57,57,58,58,58,59,59,59,60,60,60,61,61,61,62,62,62,63,63,63,64,64,64,65,65,65,66,66,66,67,67,67,68,68,68,69,69,69,70,70,70,71,71,71,72,72,72,73,73,73,74,74,74,75,75,75,76,76,76,77,77,78,78,79,79,79,79,80,80,80,80,81,81,81,81,82,82,82,82,83,83,83,83,84,84,84,84,85,85,85,85,86,86,86,86,87,87,87,87,88,88,88,88,89,89,89,89,90,90,90,90,91,91,91,91,92,92,92,92,93,93,93,93,93,94,94,94,94,94,95,95,95,95,95,96,96,96,96,96,97,97,97,97,97,98,98,98,98,98,99,99,99,99,99,100,100,100,100,100,101,101,101,101,101,102,102,102,102,102,103,103,103,103,103,104,104,104,104,105,105,105,105,106,106,106,106,107,107,107,107,108,108,108,108,109,109,109,109,110,110,110,110,111,111,111,111,112,112,112,112,113,113,113,114,114,114,115,115,116,116,117,117,118,118,119,120};
  cout << s.isPossible(A3) << endl;
}
