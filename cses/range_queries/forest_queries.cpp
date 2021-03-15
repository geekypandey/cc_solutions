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

const int M = 1e9+7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vvi dp(n, vi(n, 0));
	forn(i, n) {
		int row_sum = 0;
		string s;
		cin >> s;
		forn(j, n) {
			if(s[j] == '*') row_sum++;
			dp[i][j] = row_sum;
			if(i)
				dp[i][j] += dp[i-1][j]; // add the sum of above row if present
		}
	}

	forn(_, q) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		y1--, x1--, y2--, x2--;
		int ans = dp[y2][x2];
		if(x1>0) {
			ans -= dp[y2][x1-1];
		}
		if(y1>0) {
			ans-= dp[y1-1][x2];
		}
		if(y1>0 && x1>0) {
			ans += dp[y1-1][x1-1];
		}
		cout << ans << endl;
	}

	return 0;
}

