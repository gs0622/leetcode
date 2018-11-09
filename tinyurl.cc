/* https://leetcode.com/problems/encode-and-decode-tinyurl/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution2 {
	const string ss{"1234567890abcdefghijklmnopqrstuvwzyzABCDEDGHIJKLMNOPQRSTUVWXYZ"};
	unordered_map<string, string> urlmap;
public:
	Solution2 (){ srand(time(0)); }
	string encode(string longUrl) {
		default_random_engine gen;
		uniform_int_distribution<int> distribution(0,61);
		string shortUrl;
		for (int i=0; i<6; ++i) {
			shortUrl += ss[distribution(gen)];
		}
		shortUrl = "http://tinyurl.com/" + shortUrl;
		assert(urlmap.find(shortUrl)==end(urlmap));	// TODO: fix collision
		urlmap[shortUrl] = longUrl;
		return shortUrl;
	}
	string decode(string shortUrl) {
		return urlmap[shortUrl];
	}
};
class Solution {
	const string ss{"1234567890abcdefghijklmnopqrstuvwzyzABCDEDGHIJKLMNOPQRSTUVWXYZ"};
	unordered_map<string, string> urlmap;
public:
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		hash<string> hf;
		size_t h_val = hf(longUrl);
		string shortUrl;
		for (int i=0; i<6; ++i)
			shortUrl += ss[h_val % 62], h_val/=62;
		urlmap[shortUrl] = longUrl;
		return "http://tinyurl.com/" + shortUrl;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return urlmap[shortUrl.substr(shortUrl.size()-6, string::npos)];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
int main(){
	string longUrl = "https://leetcode.com/problems/encode-and-decode-tinyurl/description/";
	Solution2 s;
	string shortUrl = s.encode(longUrl);
	cout << shortUrl << endl;
	cout << s.decode(shortUrl) << endl;
}
