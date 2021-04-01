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
int max_k;
vvi table;
vi parent(mxN, -1), de(mxN);
int n, m;

void dfs(int i, int p=-1, int d=0) {
	parent[i] = p;
	de[i] = d;
	for(auto& e: adj[i]) {
		if(e != p) {
			dfs(e, i, d+1);
		}
	}
}

void build() {
	max_k = floor(log2(n));
	table = vvi(n+1, vi(max_k+1, -1));

	fora(i, 1, n+1) {
		table[i][0] = parent[i];
	}

	fora(k, 1, max_k+1) {
		for(int i = 1; i <= n; i++) {
			if(table[i][k-1] != -1)
				table[i][k] = table[table[i][k-1]][k-1];
		}
	}
}

void up(int& a, int d) {
	forn(i, max_k+1) {
		if(d&(1<<i)) {
			a = table[a][i];
		}
	}
}

void eql(int& a, int& b) {
	int da = de[a], db = de[b];
	if(da > db) up(a, da-db);
	else up(b, db-da);
}

int query(int a, int b) {
	eql(a, b);
	if(a == b) return a;
	for(int i = max_k; i >=0; i--) {
		if(table[a][i] != table[b][i]) {
			a = table[a][i];
			b = table[b][i];
		}
	}
	return parent[a];
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
