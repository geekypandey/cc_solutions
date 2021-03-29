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
const int mxN = 2e5+1;

vvi adj(mxN);
vi loc(mxN), eu, de, parent(mxN, -1);

// building euler tree
void dfs(int i, int p=-1, int d=0) {
	parent[i] = p;
	loc[i] = eu.size();
	eu.PB(i);
	de.PB(d);
	for(auto& e: adj[i]) {
		if(e != p) {
			dfs(e, i, d+1);
			eu.PB(i);
			de.PB(d);
		}
	}
}

vvi table, pos;

void build() {
	int n = eu.size();
	int max_k = floor(log2(n));
	table = vvi(max_k+1, vi(n));
	pos = vvi(max_k+1, vi(n));

	forn(i, n) {
		table[0][i] = de[i];
		pos[0][i] = i;
	}

	fora(k, 1, max_k+1) {
		for(int i = 0; i+(1<<k) <= n; i++) {
			int j = i + (1<<k-1);
			int p = (table[k-1][i] < table[k-1][j]?i:j);
			table[k][i] = table[k-1][p];
			pos[k][i] = pos[k-1][p];
		}
	}
}

int query(int a, int b) {
	a = loc[a], b = loc[b];
	int i = min(a, b);
	int j = max(a, b);
	int k = floor(log2(j-i+1));
	j = j - (1<<k) + 1 ;
	int p = (table[k][i] < table[k][j]? i : j);
	return eu[pos[k][p]];
}

vi val(mxN, 0);
vi ans(mxN, 0);

void dfs_build(int i, int p=-1) {
	int sum = val[i];
	for(auto& e: adj[i]) {
		if(e != p) {
			dfs_build(e, i);
			sum += ans[e];
		}
	}
	ans[i] = sum;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(1);

	build();
	forn(_, m) {
		int a, b;
		cin >> a >> b;
		val[a] += 1;
		val[b] += 1;
		int lca = query(a, b);
		val[lca] -= 1;
		int p = parent[lca];
		if(p != -1) val[p] -= 1;
	}

	dfs_build(1);
	fora(i, 1, n+1) cout << ans[i] << ' ';


	return 0;
}

