#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) time
	vector<int> sortArrayByParity1(vector<int>& A) {
		int i,j,n=A.size();
		for (i=0,j=0; i<n; ++i)
			if (A[i]%2==0) swap(A[i],A[j++]);
		return A;
	}
	// O(n) time
	vector<int> sortArrayByParity(vector<int>& A) {
		function<bool(int,int)> cmp=[](int a, int b) {
			//return (a%2==0&&b%2==1) || !(b%2==0&&a%2==1) || a<b;
			return (a%2==0&&(a+b)%2==1);
		};
		sort(A.begin(), A.end(), cmp);
		return A;
	}
};
int main(){
	Solution s;
	vector<int> A1{3,1,2,4};
	s.sortArrayByParity1(A1);
	for (auto n: A1) cout << n << " ";
	cout << endl;
	vector<int> A2{3991,3285,1,910,2534,1272,328,4300,4715,1514,2040,4050,311,3205,636,1435,4150,277,179,2089,2459,4317,3586,3368,757,4934,2056,3059,1933,235,2354,756,162,3087,3150,526,2746,1733,1917,3882,2452,4407,3051,2336,3162,1689,621,3413,3110,3943,635,4559,3997,4585,4363,3405,4052,2595,3928,945,3911,2223,3783,2277,3948,376,223,4672,2431,4506,4724,3333,2859,1080,467,4097,4444,3897,3493,2100,1526,567,2130,2830,4615,4679,2078,496,3869,3672,153,2234,3432,150,4597,4812,3613,392,351,1796};
	s.sortArrayByParity1(A2);
	for (auto n: A2) cout << n << " ";
	cout << endl;
}
