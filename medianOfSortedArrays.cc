/* https://www.quora.com/How-can-I-find-the-median-of-m-sorted-arrays
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(nlogk)
	double medianOfSortedArrays3(vector<vector<int>> &nums) {
		int m=0;
		for (auto &r: nums) m+=r.size();
		typedef vector<int>::iterator vi;
		struct mygreater {
			bool operator()(pair<vi,vi>& a, pair<vi,vi>& b) {
				return *a.first > *b.first;
			};
		};
		priority_queue<pair<vi,vi>, vector<pair<vi,vi>>, mygreater> pq;

		for (auto &r: nums)	// think why use reference
			pq.push({r.begin(), r.end()});

		int median;
		for (int i=0; i<m/2; ++i) {
			auto p=pq.top(); pq.pop();
			if (i+1==m/2) median=*p.first;
			++p.first;
			if (p.first!=p.second) pq.push(p);
		}
		if (m%2) return median;
		else return (median+*(pq.top().first))/2.0;
	}
	// O(nlogk)
	double medianOfSortedArrays2(vector<vector<int>> &nums) {
		int n=nums.size(), m=0;
		for_each(begin(nums), end(nums), [&](vector<int>& a){ m+=a.size();});

		// tuple: val,arr,idx
		struct mygreater {
			bool operator()(tuple<int,int,int>& a, tuple<int,int,int>& b){
				return get<0>(a) > get<0>(b);
			}
		};
		priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, mygreater> pq; // minheap

		for (int i=0; i<n; ++i)	// push in the 1st element from all arrays; val, array-id, array-idx
			pq.push(make_tuple(nums[i][0], i, 0));

		int med;
		for (int i=0; i<m/2; ++i) {
			tuple<int,int,int> top = pq.top(); pq.pop();
			if (i+1==m/2) med=get<0>(top);
			int arr=get<1>(top), idx=get<2>(top);
			if (idx < (int)nums[arr].size()-1)
				pq.push(make_tuple(nums[arr][idx+1], arr, idx+1)); 
		}
		if (m%2) return med;			// n is odd
		return (med + get<0>(pq.top())) / 2.0;	// n is even, get one more from pq
	}
	double medianOfSortedArrays1(vector<vector<int>> &nums) {
		int n=0;
		for (auto x: nums) n+=x.size();
		priority_queue<int, vector<int>, greater<int>> minheap;
		unordered_map<int,int> m; // map of key and its array from
		vector<vector<int>::iterator> its(nums.size());
		for (int i=0; i<n; ++i) {
			its[i] = begin(nums[i]);	// min per array
			minheap.push(*its[i]);		// push into minheap
			m[*its[i]] = i;			// update it-array mapping
		}
		int min;
		for (int i=0; i<n/2; ++i) {
			min = minheap.top();
			minheap.pop();
			++its[m[min]];
			if (its[m[min]]!=nums[m[min]].end()) {
				minheap.push(*its[m[min]]);
				m[*its[m[min]]]=m[min];
			} else {
				if (i==(n/2)-1) break; 
				int next = minheap.top();
				minheap.pop();
				++i;
				auto& it = its[m[next]];
				++it;
				minheap.push(*it);
				m[*it]=m[next];
			}
		}
		cout << n << ": " << min << endl;
		if (n%2) return min;
		return (minheap.top() + min) / 2.0;

	}
	// O(n) space ,O(nlog(n)) time, while n is the total elements
	double medianOfSortedArrays(vector<vector<int>> &nums) {
		int cnt=0;
		vector<int> res;
		for (auto x: nums) {
			res.insert(begin(res), begin(x), end(x));
			cnt+=x.size();
		}
		sort(begin(res), end(res));
		return (cnt%2)? res[cnt/2]: (res[cnt/2-1]+res[(cnt/2)])/2.0; 
	}
};
int main(){
	srand(time(0));
	vector<vector<int>> nums(10, vector<int>(10));
	int i=0;
	for (auto& n: nums)
		generate_n(begin(n), 10, [&i](){return ++i;});

	random_shuffle(begin(nums), end(nums));
	//nums[9].push_back(101);
	for (auto n: nums) {
		copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	Solution s;
	cout << s.medianOfSortedArrays2(nums) << endl;
	cout << s.medianOfSortedArrays3(nums) << endl;
}
