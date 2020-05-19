/*
Given an array A, we can perform a pancake flip:
We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.
We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

Note:

1 <= A.length <= 100
A[i] is a permutation of [1, 2, ..., A.length]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution3 {
public:
	// wrong
	vector<int> pancakeSort(vector<int>& A) {
		int n=A.size(), slope=0;
		vector<int> res;
		for (int i=1; i<n; ++i) {
			if (A[i]>A[i-1]) {
				if (slope==-1)
					res.push_back(i);	
				slope=1;
			} else {
				if (slope==1)
					res.push_back(i);	
				slope=-1;
			}
		}
		if (A[0]>A[n-1]) res.push_back(n);
		return res;
	}
};
class Node{
public:
    Node *one, *zero;
    int cnt;
};

int push(Node *root, int val){
    int mask = 1<<30;
    Node *cur = root;
    int res = 0;
    while(mask){
        if(val & mask){
            if(!cur->one)
                cur->one = new Node();
            if(cur->zero)
                res += cur->zero->cnt;
            cur = cur->one;
        } else {
            if(!cur->zero)
                cur->zero = new Node();
            cur = cur->zero;
        }
        cur->cnt++;
        mask >>= 1;
    }
    return res;
}

class Solution2 {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        Node *root = new Node();
        for(int i = 0; i < A.size(); i++){
            int n = push(root, A[i]);
            if(n < i){
                if(n == 0){
                    if(i > 1) res.push_back(i);
                    res.push_back(i+1);
                } else {
                    res.push_back(i+1);
                    if(i+1-n > 1) res.push_back(i+1-n);
                    if(i-n > 1) res.push_back(i-n);
                    res.push_back(i+1);
                }
            }
        }
        return res;
    }
};
class Solution {
public:
	// O(n^2) flips in 2n
	vector<int> pancakeSort(vector<int>& A) {
		int n=A.size(),i,j;
		vector<int> res;
		for (i=n; i>0; --i) {
			for (j=0; A[j]!=i; ++j);
			reverse(A.begin(), A.begin()+j+1);	// A[j] to A[0]
			res.push_back(j+1);
			reverse(A.begin(), A.begin()+i);	// A[j] to A[A[j]-1]
			res.push_back(i);
		}
		return res;
	}
};
int main(){
	Solution3 s;
	vector<int> A1{1,2,3};
	//vector<int> A1{3,2,4,1};
	for (auto n: s.pancakeSort(A1)) cout << n << " ";
	cout << endl;
}
