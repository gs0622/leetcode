#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
  n+1 buckets
		<- count
  B0 B1 ... Bn
*/
class Solution {
public:
	int hIndex(vector<int>& c) {
		int mi, lo=0, hi=c.size()-1, sz=c.size();
		while (lo<=hi) {
			mi = lo+(hi-lo)/2;
			if (c[mi] == sz-mi) return c[mi]; // all right ones are larger than c[mi]
			else if (c[mi] > sz-mi) hi=mi-1;
			else lo=mi+1;
		}
		return sz==0? 0: sz-hi-1;
	}
	int hIndex2(vector<int>& citations) {
		int n = citations.size();
		vector<int> buckets(n+1, 0);
		for (auto c: citations) {
			if (c >= n) buckets[n] +=1; // exception case
			else buckets[c] += 1; // into the bucket
		}
		int c = 0; // <- count from the largest bucket
		for (int i=n; i>=0; --i) {
			c+= buckets[i];
			if (c >= i) return i;
		}
		return 0;
	}
};
int main(){
	vector<int> H{0};
	//vector<int> H{0,1,3,5,6};
	//vector<int> H{1,3,1};
	//vector<int> H{3,0,6,1,5};
	//vector<int> H{100};
	Solution s;
	cout << s.hIndex(H) << endl;
}
