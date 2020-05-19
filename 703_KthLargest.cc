#include <bits/stdc++.h>
using namespace std;
class KthLargest {
	int K;
	vector<int> A;
public:
	KthLargest(int k, vector<int> nums) {
		K = k;
		A=nums;
		sort(A.begin(), A.end());	
	}
	int add(int val) {
		A.insert(lower_bound(A.begin(), A.end(), val), val);
		return A[A.size()-K];
	}
};
int main(){
	vector<int> A1{4,5,8,2};
	KthLargest kthLargest = KthLargest(3, A1);
	cout << kthLargest.add(3) << endl;   // returns 4
	cout << kthLargest.add(5) << endl;   // returns 5
	cout << kthLargest.add(10) << endl;  // returns 5
	cout << kthLargest.add(9) << endl;   // returns 8
	cout << kthLargest.add(4) << endl;   // returns 8
}

