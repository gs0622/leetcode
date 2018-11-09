#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	// O(log(mn))
	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		int m=matrix.size(), n=matrix[0].size();
		int lo=0, hi=m*n-1;
		while (lo<hi) {
			int mi=lo+(hi-lo)/2;
			if (matrix[mi/n][mi%n]<target) lo=mi+1;
			else if (matrix[mi/n][mi%n]>target) hi=mi;
			else return true;
		}
		return matrix[lo/n][lo%n]==target;
	}
	bool searchMatrix1(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		int row = 0, col = matrix[0].size()-1;
		while (row < matrix.size() && col >= 0) {
			if (matrix[row][col] == target) return true;
			if (matrix[row][col] < target) row++; // the largest of the row
			else col--; // [r][c] > target, the smallest of the col
		}
		return false;
	}
	// O(mn), Brute-force
	bool searchMatrix0(vector<vector<int>>& matrix, int target) {
		for (auto row: matrix) {
			for (auto n: row) {
				if (n==target)
					return true;
			}
		}
		return false;
	}
};
int main() {
	vector<vector<int> > m { {1,4,7,11,15},
				 {2,5,8,12,19},
				 {3,6,9,16,22},
				 {10,13,14,17,24},
				 {18,21,23,26,30} };
	Solution s;
	cout << "5: " << s.searchMatrix0(m, 5) << " " << s.searchMatrix2(m, 5) << endl;
	cout << "20: " << s.searchMatrix0(m, 20) << " " << s.searchMatrix2(m, 20) << endl;
}
