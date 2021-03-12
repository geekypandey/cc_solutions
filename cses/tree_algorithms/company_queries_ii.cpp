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

int n, q;
const int mxN = 2e5+1;
vi adj[mxN], euler, who, loc(mxN);

void dfs(int i, int d=0) {
	loc[i] = euler.size();
	euler.PB(d);
	who.PB(i);
	for(auto& e: adj[i]) {
		dfs(e, d+1);
		euler.PB(d);
		who.PB(i);
	}
}

vvi table, pos;

void build() {
	int n = euler.size();
	int maxk = log2(n);
	table = vvi(maxk+1, vi(n));
	pos = vvi(maxk+1, vi(n));

	forn(i, n) {
		table[0][i] = euler[i];
		pos[0][i] = i;
	}

	fora(k, 1, maxk+1) {
		for(int i = 0; i+(1<<k)<=n; i++) {
			// When can we stop the looping
			int j = i+(1<<(k-1));
			if(table[k-1][i] < table[k-1][j]) {
				table[k][i] = table[k-1][i];
				pos[k][i] = pos[k-1][i];
			} else {
				table[k][i] = table[k-1][j];
				pos[k][i] = pos[k-1][j];
			}
			/* table[k][i] = min(table[k-1][i], table[k-1][i+(1<<k-1)]); */
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;

	fora(i, 2, n+1) {
		int a;
		cin >> a;
		adj[a].PB(i);
	}

	// Step 1: build the euler tour
	dfs(1);

	// Step 2: Build the sparse table
	build();

	forn(_, q) {
		int a, b;
		cin >> a >> b;
		// answer the query
		int start = loc[a], end = loc[b];
		int k = log2(abs(end-start) + 1);
		int i = min(start, end), j = max(start, end);
		j = j - (1<<k) +1;
		int ans;
		if(table[k][i] < table[k][j]) {
			ans = pos[k][i];
		} else {
			ans = pos[k][j];
		}
		ans = who[ans];
		cout << ans << endl;
	}

	return 0;
}

