#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct mycmp
{
    inline bool operator() (const vector<string>& a, const vector<string>& b)
    {
        return a.size() > b.size();
    }
};

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string> > m;
        int i = 0;
        for (auto s: strs) {
            sort(s.begin(), s.end());
            m[s].push_back(strs[i++]);
        }
        std::vector<vector<string> > r;
        int j = 0;
        for (auto x: m) {
            sort(x.second.begin(), x.second.end());
            r.push_back(x.second);
            //cout << "k: " << x.first << endl;
        }
        sort(r.begin(), r.end(), mycmp());
        return r;
    }
};

int main(void)
{
    const char *strs[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<string> v (strs, strs+6);
    Solution s;
    std::vector<vector<string> > r = s.groupAnagrams(v);
    for (auto x: r) {
        for (auto y: x)
            std::cout << y << " ";
        std::cout << endl;
    }
    return 0;
}
