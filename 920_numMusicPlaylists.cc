/* Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.
You create a playlist so that:
Every song is played at least once
A song can only be played again only if K other songs have been played
Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int numMusicPlaylists(int N, int L, int K) {
		vector<vector<long>> dp(N+1, vector<long>(L+1,0));
		const long mod=1e9+7;
		function<long(int)> helper=[&](int n) { return n? helper(n-1)*n%mod: 1; };	// n factorial
		for (int i=K+1; i<=N; ++i) {
			for (int j=i; j<=L; ++j) {
				if (i==j || i==K+1)	// n factorical combinations
					dp[i][j]=helper(i);
				else			// F(N,L,K) = F(N-1,L-1,K)*N + F(N,L-1,K) * (N-K)
					dp[i][j]=(dp[i-1][j-1]*i + dp[i][j-1]*(i-K))%mod;
			}
		}
		return (int)dp[N][L];
	}
};
int main(){
	Solution s;
	cout << s.numMusicPlaylists(3,3,1) << endl;
	cout << s.numMusicPlaylists(2,3,0) << endl;
	cout << s.numMusicPlaylists(2,3,1) << endl;
	cout << s.numMusicPlaylists(3,3,2) << endl;
}
