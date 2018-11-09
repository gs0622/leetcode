#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findLonglyPixel(vector<vector<char>>& pic) {
		int m=pic.size(), n=pic[0].size();
		vector<int> rowcnt(m, 0), colcnt(n,0);
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (pic[i][j] == 'B')
					++rowcnt[i], ++colcnt[j];
		int res=0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (pic[i][j] == 'B')
					if (rowcnt[i]==1 && colcnt[j]==1)
						++res;
		return res;
	}
};
int main(){
	Solution s;
	vector<vector<char>> pic{{'W','W','B'},
				 {'W','B','W'},
				 {'B','W','W'}};
	cout << s.findLonglyPixel(pic) << endl;
}
