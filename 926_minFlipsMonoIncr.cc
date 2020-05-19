#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
                int cnt[2]={0};
                for (auto c: s) {
                        if (c=='1') ++cnt[0];           // flip 1
                        else ++cnt[1];                  // flip 0
                        cnt[1]=min(cnt[0],cnt[1]);      // starting from the 1st 1
                }
                return cnt[1];
    }
};
int main(){
	vector<int> nums(10);
	Solution s;
}
