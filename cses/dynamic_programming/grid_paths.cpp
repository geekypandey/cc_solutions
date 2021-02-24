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

const int mx = 1000;
int n;
vector<vector<bool>> v(mx, vector<bool>(mx, true));
vvl dp(mx, vl(mx, 0));

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	forn(i, n) {
		forn(j, n) {
			char c;
			cin >> c;
			if(c == '*')
				v[i][j] = false;
		}
	}

	const int M = 1e9+7;
	dp[0][0] = 1;
	forn(i, n) {
		forn(j, n) {
			if(!v[i][j]) continue;
			if(i+1<n && v[i+1][j])
				dp[i+1][j] = (dp[i+1][j]%M + dp[i][j]%M)%M;
			if(j+1<n && v[i][j+1])
				dp[i][j+1] = (dp[i][j+1]%M + dp[i][j]%M)%M;
		}
	}
	if(v[0][0]==false || v[n-1][n-1] == false)
		cout << 0 << endl;
	else
		cout << dp[n-1][n-1] << endl;

	return 0;
}

