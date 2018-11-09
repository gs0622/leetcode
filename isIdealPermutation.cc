/* https://leetcode.com/problems/global-and-local-inversions/description/
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool isIdealPermutation(vector<int>& A) {
		for (int i=0; i<A.size(); ++i)
			if (abs(A[i]-i) > 1) return false;
		return true;
	}
	bool isIdealPermutation2(vector<int>& A) {
		int G=0, L=0;
		for (int i=0; i<A.size(); ++i) {
			for (int j=i+1; j<A.size(); ++j) {
				if (A[i]>A[j]) {
					if (j==i+1) L+=1;
					G+=1;
				}
			}
		}
		return G==L;
	}
};
int main(){
	Solution s;
	vector<int> A1{1,0,2};
	cout << s.isIdealPermutation(A1) << endl;
	vector<int> A2{1,2,0};
	cout << s.isIdealPermutation(A2) << endl;
}
