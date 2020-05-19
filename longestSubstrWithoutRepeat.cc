/* https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution4 { // brute-force O(n^2)
public:
    int lengthOfLongestSubstring(string s) {
        int res=0, n=s.size(), i, j;
        for (i=0; i<n; ++i) {
            int cnt[256]={};      // counter map
            for (j=i; j<n; ++j) {
                ++cnt[s[j]];      // see s[j]
                if (cnt[s[j]]>1) break; // repeat
            }
            res=max(res,j-i);     // j is the repeat; (j-1)-i+i
        }
        return res;
    }
};

class Solution3 {
public:
	int lengthOfLongestSubstring(string s) {
		int cnt[256]={};		// ascii only
		int res=0, sub=0, n=s.size();
		for (int i=0,j=0; i<n; ++i) {
			//if (cnt[s[i]]==0) ++sub;		// invariant
			++cnt[s[i]];				// seen
			while (cnt[s[i]]>1) {			// maintain invariant
			//if (cnt[s[i]]>1) {			// think why if is not working: pwwkew; because it's j moving
				--cnt[s[j++]];
				//if (cnt[s[j]]==0) --sub;
				//++j;
			}
			res = max(res, i-j+1);			// update window length
		}
		return res;
	}
};
class Solution2 {
public:
	// O(n) two pointers
	int lengthOfLongestSubstring(string s) {
		int cnt[256]={};
		int res=0, n=s.size();
		for (int i=0, j=0; i<n; ++i) {
			cnt[s[i]]++;				// seen
			while (cnt[s[i]]>1)			// maintain invariant
				--cnt[s[j]], ++j;
			res=max(res, i-j+1);
		}
		return res;
	}
};
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
    Solution2 s;
    Solution3 ss;
    string s0("abcabcbb");
    string s1("bbbbb");
    string s2("pwwkew");
    string s3("dvdf");
/*    cout << ss.lengthOfLongestSubstring(s0) << " ";
    cout << s.lengthOfLongestSubstring(s0) << endl;
    cout << ss.lengthOfLongestSubstring(s1) << " ";
    cout << s.lengthOfLongestSubstring(s1) << endl;*/
    cout << ss.lengthOfLongestSubstring(s2) << " ";
    cout << s.lengthOfLongestSubstring(s2) << endl;
    cout << ss.lengthOfLongestSubstring(s3) << " ";
    cout << s.lengthOfLongestSubstring(s3) << endl;
    return 0;
}
