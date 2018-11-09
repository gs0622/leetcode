/* Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.
hint: greedy
*/
class Solution {
public:
	// For each B[i], we select the smallest number in A that is greater than B[i].
	// If there are no such number, we select the smalest number in A
	vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		multiset<int> AA(A.begin(), A.end());
		vector<int> res(B.size());
		for (int i=0; i<B.size(); ++i) {
			//auto it=*AA.rbegin()<=B[i]? AA.begin(): AA.upper_bound(B[i]);
			auto it=*AA.rbegin()>B[i]? AA.upper_bound(B[i]): AA.begin();
			res[i]=*it;
			AA.erase(it);
                }
                return res;
	}
	// Wrong
	// 15 / 67 test cases passed.
	// Input:	[2,0,4,1,2], [1,3,0,0,2]
	// Output:	[1,4,0,2,0]
	// Expected:	[2,0,2,1,4]	
	vector<int> advantageCount0(vector<int>& A, vector<int>& B) {
		set<int> AA(A.begin(), A.end());
		vector<int> res(B.size());
		for (int i=0; i<B.size(); ++i) {
			auto it=AA.lower_bound(B[i]);
			auto tmp=(it==AA.end())?*AA.begin(): *it;
			res[i]=tmp;
			AA.erase(tmp);
		}
                return res;
    }
};
#include <bits/stdc++.h>
using namespace std;
int main(){
	Solution s;
	vector<int> A{2,7,11,15}, B{1,10,4,11};
}
