/* https://leetcode.com/problems/koko-eating-bananas/description/

Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.

Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

Return the minimum integer K such that she can eat all the bananas within H hours.

#integer ceil: https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int minEatingSpeed1(vector<int>& piles, int H) {
		int lo=1, hi=1e9;	// search space [1,1e9]
		function<bool(int)> helper=[&](int K) {
			int hrs=0;
			for (auto pile: piles) hrs += (pile+K-1)/K;
			return hrs <= H;
		};
		while (lo<=hi) {
			int mi=lo+(hi-lo)/2;
			if (helper(mi)) hi=mi-1;
			else lo=mi+1;
		}
		return lo;
	}
	// O(nlog(10^9))?
	int minEatingSpeed(vector<int>& piles, int H) {
		int lo=1, hi=1e9;	// tricky: lo=1
		while (lo<hi) {
			int mi=lo+(hi-lo)/2, total=0;
			for (auto b: piles)
				total+=(b+mi-1)/mi;	// round up as ceil(b/mi), 1+(b-1)/mi
			if (total>H) lo=mi+1;		// too fast
			else hi=mi;
		}
		return lo;	// return lowest K
	}
};
int main(){
	Solution s;
	vector<int> A1{3,6,7,11};
	cout << s.minEatingSpeed1(A1,8) << endl;
	vector<int> A2{30,11,23,4,20};
	cout << s.minEatingSpeed1(A2,5) << endl;
	vector<int> A3{312884470};
	cout << s.minEatingSpeed1(A3,968709470) << endl;
}
