#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	// O(n^4)
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int i, j, k, l, ans = 0;
		for (i=0; i<A.size(); i++)
			for (j=0; j<B.size(); j++)
				for (k=0; k<C.size(); k++)
					for (l=0; l<D.size(); l++) {
						if (A[i]+B[j]+C[k]+D[l]==0) {
							ans += 1;
							//cout << i << j << k << l << endl;
						}
					}
		return ans;
	}
	int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int i, j, k, l, ans = 0;
		unordered_map<int, int> mD;
		for (l=0; l<D.size(); l++)
			mD[D[l]] = i; // array value as key 
		for (i=0; i<A.size(); i++)
			for (j=0; j<B.size(); j++)
				for (k=0; k<C.size(); k++) {
					int sum = A[i]+B[j]+C[k];
					auto it = mD.find(-sum);
					if (it != mD.end()) ans += 1;
				}
		return ans;
	}
	// O(n^2) time and space, by hashmap record two-sum, then calculate four-sum, this reduces O(n^4) to O(n^2) 
	int fourSumCount3(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int i, j, k, l, ans = 0;
		unordered_map<int, int> m;
		for (i=0; i<A.size(); i++)
			for (j=0; j<B.size(); j++)
				m[A[i]+B[j]] += 1;
		for (k=0; k<C.size(); k++)
			for (l=0; l<D.size(); l++) {
				int sum = C[k] + D[l];
				auto it = m.find(-sum);
				if (it != m.end()) ans += it->second;
			}
		return ans;
		
	}
};
int main(){
	vector<int> A{1,2};
	vector<int> B{-2,-1};
	vector<int> C{-1,2};
	vector<int> D{0,2};
	Solution s;
	cout << s.fourSumCount(A,B,C,D) << endl;
	cout << s.fourSumCount2(A,B,C,D) << endl;
	cout << s.fourSumCount3(A,B,C,D) << endl;
}

