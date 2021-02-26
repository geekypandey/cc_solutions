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

int n, m;
vector<vector<char>> v;

void dfs(int i, int j) {
	if(i<0 || j < 0 || i>=n || j >=m || v[i][j] == '#') return;
	v[i][j] = '#';
	dfs(i-1, j);
	dfs(i+1, j);
	dfs(i, j+1);
	dfs(i, j-1);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	v = vector<vector<char>>(n, vector<char>(m));

	for(auto& row: v) {
		for(auto& col: row) cin >> col;
	}

	ll ans = 0;
	forn(i, n) {
		forn(j, m) {
			if(v[i][j] == '#') continue;
			ans++;
			dfs(i, j);
		}
	}
	cout << ans << endl;


	return 0;
}
