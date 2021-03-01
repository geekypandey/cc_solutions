#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;


#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fora(i, a, n) for(ll i = a; i < n; i++)
#define readi(e) int e; cin >> e
#define readl(e) ll e; cin >> e
#define reads(e) string e; cin >> e
#define T int tt; cin >> tt; while(tt--)


template<typename U>
void print(U arr) {
	for(auto element: arr) {
		cout << element << " ";
	}
	cout << endl;
}

// read and write into files, rather than standard i/o
void setup(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, x;
	cin >> n >> x;

	vi p(n);
	vi pa(n);
	for(auto& e: p) cin >> e;
	for(auto& e: pa) cin >> e;

	vvi dp(n, vi(x+1, 0));

	forn(i, n) {
		fora(s, 1, x+1) {
			// using the ith item
			if(s-p[i]>=0) { // able to pay the price
				dp[i][s] = pa[i];
				if(i-1>=0)
					dp[i][s] += dp[i-1][s-p[i]];
			}
			if(i-1>=0)
					dp[i][s] = max(dp[i][s], dp[i-1][s]);
		}
	}
	// what does dp[n][x] means
	cout << dp[n-1][x] << endl;

	return 0;
}
