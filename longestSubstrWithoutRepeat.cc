#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// O(n) two pointers
	int lengthOfLongestSubstring2(string s) {
		unordered_map<char,int> m;				// map records occurant position
		int res=0;
		for (int i=0,j=0; i<s.size(); ++i) {			// two pointers: i for running, j for valid begin (next by repeat)
			if (m.count(s[i]))
				j = max(j, m.find(s[i])->second)+1;	// j: update begin by next char of the repeat
			m[s[i]] = i;					// update position
			res = max(res, i-j+1);				// must: update max len, +1 for idx of begin is count
		}
		return res;
	}
	int lengthOfLongestSubstring1(string s) {
		vector<int> map(256, -1);				// array records occurant, -1 gives i-beg correct length
		int res=0, beg=-1;
		for (int i=0; i<s.size(); ++i) {
			if (map[s[i]]>beg)	// repeat, update begin position
				beg = map[s[i]];
			map[s[i]]=i;
			res=max(res, i-beg);	// update max len
		}
		return res;
	}
    int lengthOfLongestSubstring(string s) {
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

int longest(string s) {
    unordered_map<char, int> um;
    int cnt = 0, max = 0;
    for (char c: s) {
        um[c]++;
        if (um[c] < 2)
            cnt++, max = std::max(max, cnt);
        else
            um.clear(), um[c] = 1, cnt = 1;
    }
    return max;
}

int main(void) {
    Solution s;
    string s0("abcabcbb");
    string s1("bbbbb");
    string s2("pwwkew");
    string s3("dvdf");
    cout << s.lengthOfLongestSubstring1(s0) << " ";
    cout << s.lengthOfLongestSubstring2(s0) << endl;
    cout << s.lengthOfLongestSubstring1(s1) << " ";
    cout << s.lengthOfLongestSubstring2(s1) << endl;
    cout << s.lengthOfLongestSubstring1(s2) << " ";
    cout << s.lengthOfLongestSubstring2(s2) << endl;
    cout << s.lengthOfLongestSubstring1(s3) << " ";
    cout << s.lengthOfLongestSubstring2(s3) << endl;
    return 0;
}
