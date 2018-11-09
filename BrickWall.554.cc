#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int leastBricks(vector<vector<int> >& wall) {
		std::unordered_map<int, int> m;
		std::unordered_map<int,int>::iterator it;
		int ans = wall.size();
		for (auto i: wall) {
			int s = 0;
			for (int j = 0; j < i.size()-1; j++) {
				s += i[j]; // edge location;
				auto it = m.find(s); // hash 's' as key
				if (it != m.end())
					m[s] = m[s]+1; // edges as value
				else
					m[s] = 1; 
				
			}
			for (auto k: m) {
				int tmp = wall.size()-k.second; // crossed bricks
				//if (tmp < ans)
				//	std::cout << k.first << ": " << tmp << endl; // width: bricks
				ans = std::min(ans, tmp);
			}
		}
		return ans;
	}
};

int main(void)
{
	std::vector<int> v[6];

	for (auto i: {1,2,2,1}) v[0].push_back(i);
	for (auto i: {3,1,2}  ) v[1].push_back(i);
	for (auto i: {1,3,2}  ) v[2].push_back(i);
	for (auto i: {2,4}    ) v[3].push_back(i);
	for (auto i: {3,1,2}  ) v[4].push_back(i);
	for (auto i: {1,3,1,1}) v[5].push_back(i);

	std::vector<vector<int> > vv(v, v+5);
	Solution s;
	std::cout<< s.leastBricks(vv) << endl;
	return 0;
}
