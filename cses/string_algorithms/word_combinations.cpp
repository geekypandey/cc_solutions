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
int ans = 0;

int k;
string s;
vector<string> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s >> k;
	v=vector<string>(k);
	for(auto& e: v) cin >> e;
	int n = s.length();
	vi dp(n+1, 0);
	// string s
	// multiple strings
	dp[0] = 1;
	for(int i=1; i <=n; i++) {
		for(auto& e: v) {
			int m = e.size();
			if(i<m) continue;
			bool y=1;
			for(int j = 0; j < m&& y; j++) {
				if(s[i-m+j] != e[j]) y=0;
			}
			if(y)
				dp[i] = (dp[i]+dp[i-m])%M;
		}
	}
	cout << dp[n] << endl;


	return 0;
}
