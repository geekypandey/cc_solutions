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
const int mxN = 1e6;

struct {
	int c[mxN+1][26], en[mxN+1], m = 1;

	void ins(string s) {
		int u = 0;
		for(auto& a: s) {
			if(!c[u][a-'a']) c[u][a-'a'] = m++;
			u = c[u][a-'a'];
		}
		en[u] = 1;
	}
} ac;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.length();

	int k;
	cin >> k;
	vector<string> v(k);
	for(auto& e: v) {cin >> e; ac.ins(e);}

	vector<int> dp(n+1, 0);
	dp[0] = 1;
	forn(i, n) {
		int u = 0;
		fora(j, i, n) {
			u = ac.c[u][s[j]-'a'];
			if(!u) break;
			if(ac.en[u])
				dp[j+1] = (dp[j+1] + dp[i])%M;
		}
	}
	cout << dp[n] << endl;




	return 0;
}

