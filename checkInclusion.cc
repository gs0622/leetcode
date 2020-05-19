/* https://leetcode.com/problems/permutation-in-string/description/

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
        // maintain a sliding window of char map to detect the map equal between s and p
        vector<int> findAnagrams(string s, string p) {
                vector<int> pv(256,0), sv(256,0), res;
                if (s.size() < p.size()) return res;
      
		for (int i=0; i<p.size(); ++i)			// fill pv, sv 
                        ++pv[p[i]], ++sv[s[i]];

                if (pv == sv)
			res.push_back(0); // tricky to learn: vector's equal operator ==

                for (int i=p.size(); i <s.size(); ++i) {	// sliding window
                        ++sv[s[i]];				// include
                        --sv[s[i-p.size()]];			// remove
                        if (pv == sv)
                                res.push_back(i-p.size()+1);
                }
                return res; // indices arr
        }
public:
	bool checkInclusion(string s1, string s2) {
		return findAnagrams(s2, s1).size();
	}
};
int main(){
	Solution s;
	string s1{"ab"}, s2{"eidbaooo"};
	cout << s.checkInclusion(s1, s2) << endl; 
}
