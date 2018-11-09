/* given n, count the occurance of 2 from 1 to n
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int count(int n) {
		int cnt1=0;
		for (int i=1; i<=n; ++i) {
			int cnt2=0, j=i;
			while (j>0) {
				if (j%10 ==2) ++cnt2;
				j/=10;
			}
			cnt1+=cnt2;
		}
		return cnt1;
	}
};
int main(){
	Solution s;
	cout << s.count(22) << endl;
}
