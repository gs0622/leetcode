#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);			// small universe, worth it
    int maxlen = 0, start = -1;
    for (int i = 0; i < s.size(); i++) {
      if (dict[s[i]] > start)			// repeat
        start = dict[s[i]];		// valid start
		  dict[s[i]] = i;				// update pos
		  maxlen = std::max(maxlen, i - start);
        }
        return maxlen;
    }
    // wrong
    int lengthOfLongestSubstring2(string s) {
        unordered_map<char, int> um; 
        int cnt = 0, max = 0;
        for (char c: s) {
            um[c]++;
            if (um[c] < 2) {
                cnt++;
                max = std::max(max, cnt);
            } else {
                um.clear();
                um[c] = 1;
                cnt = 1;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    string s0("abcabcbb");
    string s1("bbbbb");
    string s2("pwwkew");
    string s3("dvdf");
    cout << s0 << ": " << s.lengthOfLongestSubstring(s0) << ": " << s.lengthOfLongestSubstring2(s0) << endl;
    cout << s1 << ": " << s.lengthOfLongestSubstring(s1) << ": " << s.lengthOfLongestSubstring2(s1) << endl;
    cout << s2 << ": " << s.lengthOfLongestSubstring(s2) << ": " << s.lengthOfLongestSubstring2(s2) << endl;
    cout << s3 << ": " << s.lengthOfLongestSubstring(s3) << ": " << s.lengthOfLongestSubstring2(s3) << endl;
    return 0;
}
