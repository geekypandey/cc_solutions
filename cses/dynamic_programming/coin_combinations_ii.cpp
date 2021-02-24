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

	const ll M = 1e9+7;
	ll n, x;
	cin >> n >> x;
	vi v(n);
	for(auto& e: v) cin >> e;

	vvi dp(x+1, vi(n, 0));
	dp[0][0] = 1;
	fora(i, 0, x) {
		forn(j, n) {
			if(i + v[j] <= x)
				dp[i+v[j]][j] = (dp[i+v[j]][j]%M + dp[i][j]%M)%M;
			if(j+1 < n)
				dp[i][j+1] = (dp[i][j+1]%M + dp[i][j]%M)%M;
		}
	}

	cout << accumulate(all(dp[x]), 0) << endl;
	return 0;
}

