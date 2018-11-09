#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int mi, lo=0, hi=arr.size()-k;
		while (lo<hi) {
			mi = (lo+hi)/2; // lo<=mi<hi, mi+k<=arr.size()
			if (x-arr[mi] > arr[mi+k]-x) // make mi+k (with in size) close to x
				lo = mi+1;
			else
				hi=mi;
		}
		vector<int> ret(arr.begin()+lo, arr.begin()+lo+k);
		return ret;
	}
	vector<int> findClosestElements1(vector<int>& arr, int k, int x) {
		auto lower = lower_bound(begin(arr), end(arr), x);
		int end = lower-arr.begin(), start = end-1, n = arr.size();
		while (k--) {
			if (start < 0) ++end;
			else if (end < n && (x-arr[start])>arr[end]-x) ++end;
			else --start;
		}
		return vector<int>(arr.begin()+start+1, arr.begin()+end);
	}
	vector<int> findClosestElements2(vector<int>& arr, int k, int x) {
		int lower_bound = 0;
		for (int i = 0; i < arr.size(); ++i) { // find lower_bound
			if (arr[i] >= x) {
				if (i > 0) {
					lower_bound = abs(arr[i-1]-x) < abs(arr[i]-x)? i-1: i;
				} else
					lower_bound = i;
				break;
			}
		}
		int end = lower_bound, start = end-1;
		while (k) {
			if (start < 0) ++end;
			else if (end<arr.size() && abs(x-arr[start]) > abs(arr[end]-x)) ++end;
			else --start;
			k -= 1;
		}
		//cout << "l=" << lower_bound << " s=" << start << " e=" << end << endl;
		return vector<int>(arr.begin()+start+1, arr.begin()+end);
	}
};
int test1(){
	vector<int> A {1,2,3,4,5};
	Solution s;
	vector<int> r = s.findClosestElements(A, 4, 3);
	for (auto x: r) cout << x << " ";
	cout << endl;
	r.clear();
	r = s.findClosestElements1(A, 4, 3);
	for (auto x: r) cout << x << " ";
	cout << endl;
}
int test2(){
	vector<int> A {0,0,0,1,3,5,6,7,8,8};
	Solution s;
	vector<int> r = s.findClosestElements(A, 2, 2);
	for (auto x: r) cout << x << " ";
	cout << endl;
	r.clear();
	r = s.findClosestElements2(A, 2, 2);
	for (auto x: r) cout << x << " ";
	cout << endl;
}
int test3(){
	vector<int> A {1,2,5,5,6,6,7,7,8,9};
	Solution s;
	vector<int> r = s.findClosestElements(A, 7, 7);
	for (auto x: r) cout << x << " ";
	cout << endl;
	r.clear();
	r = s.findClosestElements2(A, 7, 7);
	for (auto x: r) cout << x << " ";
	cout << endl;
}
int test4(){
	vector<int> A {0,1,2,2,2,3,6,8,8,9};
	Solution s;
	vector<int> r;
	r = s.findClosestElements(A, 5, 9);
	for (auto x: r) cout << x << " ";
	cout << endl;
	r.clear();
	r = s.findClosestElements1(A, 5, 9);
	for (auto x: r) cout << x << " ";
	cout << endl;
}
int main(){
	test1();
	//test2();
	//test3();
	test4();
}
