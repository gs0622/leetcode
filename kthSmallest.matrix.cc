/* https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

Good reference: 
https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
public:
  int kthSmallest(vector<vector<int>>& m, int k) {
    int n=m.size(),lo=m[0][0],hi=m[n-1][n-1];
    while (lo<hi) { // n*log(n)*log(hi-lo)
      int mi=lo+(hi-lo)/2,cnt=0;
      for (int r=0;r<n;++r)
        cnt+=upper_bound(m[r].begin(),m[r].end(),mi)-m[r].begin();
      if (cnt<k) lo=mi+1;
      else hi=mi;
    }
    return lo;
  }
}
class Solution {
	struct compare {
		bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b) {
			return a.first>b.first;
		}
	};
public:
	// O(max(n, k)*log(n)), O(klog(k))
	int kthSmallest4(vector<vector<int>>& m, int k) {
		int n=m.size();
		struct mygreater {
			bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b){
				return get<0>(a) > get<0>(b);
			}
		};
		priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, mygreater> pq;	// minheap of value
		for (int i=0; i<n; ++i)				// the smallest candidates in col[0]
			pq.push(make_tuple(m[i][0], i, 0));	// key for priority / row / col

		int cnt=k, res;
		while (cnt-- && !pq.empty()) {	// max(n,k)
			tuple<int,int,int> top = pq.top(); pq.pop();	// pick the smallest one
			int val = get<0>(top), row = get<1>(top), col = get<2>(top);
			res = val;
			if (col < n) // next candidate either already in pool, or on same row of current one
				pq.push(make_tuple(m[row][col+1], row, col+1));	// next cand shall include same row, col+1
		}
		return res;
	}
	// O(n^2log(n))
	int kthSmallest3(vector<vector<int>>& m, int k) {
		int n=m.size();	// n-by-n
		priority_queue<int> pq;		// maxheap w/ limitation of k emelemts
		for (auto row: m) {		// iterate all elems, keep k largest only
			for (auto cell: row) {
				pq.push(cell);
				if (pq.size()>k)
					pq.pop();
			}
		}
		return pq.top();	// top is max w/ k-1 smaller ones
	}

	// O(n*log([max]-[min])), [max]-[min] depicts the search space  
	int kthSmallest2(vector<vector<int>>& m, int k) {
		int n=m.size(), lo=m[0][0], hi=m[n-1][n-1];		// search-space in between [min] and [max] elem
		while (lo<hi) {
			int mi=lo+(hi-lo)/2, cnt=0;			// cnt is for counting the ones smaller than mi
			for (int i=0, j=n-1; i<n; ++i) {		// tricky: evaluate mi by transforming mi to cnt
				while (j>=0 && m[i][j]>mi) --j;		// this could improve further by upper_bound call
				cnt += j+1;
			}
			if (cnt < k) lo=mi+1;				// evaluate cnt against mi
			else hi=mi;					// tricky: this helps to regulate search space
		}
		return lo; // lo==hi
	}
	int kthSmallest1(vector<vector<int>>& m, int k) {
		int n = m.size();			// n-by-n matrix
		int lo=m[0][0], hi=m[n-1][n-1];
		while (lo<hi) {
			int mi = lo+(hi-lo)/2, cnt=0;
			for (int r=0; r<n; ++r) {	// transfer mi to cnt in search space
				cnt += distance(begin(m[r]) , upper_bound(begin(m[r]), end(m[r]), mi));
			}
			if (cnt < k) lo=mi+1;
			else hi = mi;
		}
		return lo;
	}
	// O(n^2) brute-force
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		vector<int> arr;
		for (auto row: matrix) {
			for (auto v: row) {
				arr.push_back(v);
			}
		}
		std::sort(arr.begin(), arr.end());	// sorting is required!
		return arr[k-1];
	}
};
int main(){
	vector<vector<int>> m{	{1,5,9},
				{10, 11, 13},
				{12, 13, 15}};
	Solution s;
	cout << s.kthSmallest(m, 8) << ": ";
	cout << s.kthSmallest3(m, 8) << ": ";
	cout << s.kthSmallest4(m, 8) << endl;
}
