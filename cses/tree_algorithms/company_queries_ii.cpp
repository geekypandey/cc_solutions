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
vi adj[mxN];
vi euler, loc(mxN, 0), who;
 
// Euler tour
void dfs(int i, int depth=0) {
	loc[i] = euler.size();
	euler.PB(depth);
	who.PB(i);
	for(auto& e: adj[i]) {
		dfs(e, depth+1);
		euler.PB(depth);
		who.PB(i);
	}
	return;
}
 
vvi table, pos;
 
void build() {
	int n = euler.size();
	int k = log2(n);
	table = vvi(k+1, vi(n)), pos = vvi(k+1, vi(n));
 
	forn(i, n) {
		table[0][i] = euler[i];
		pos[0][i] = i;
	}
	fora(i, 1, k+1) {
		forn(j, n) {
			int to = j+pow(2, i)-1;
			if(to < n) {
				if(table[i-1][j] < table[i-1][to]) {
					pos[i][j] = pos[i-1][j];
					table[i][j] = table[i-1][j];
				} else {
					pos[i][j] = pos[i-1][to];
					table[i][j] = table[i-1][to];
				}
			}
		}
	}
}
 
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> n >> q;
	fora(i, 2, n+1) {
		int b;
		cin >> b;
		adj[b].PB(i);
	}
 
	// Step 1: Build a Euler list
	dfs(1);
	// Done
	// Step 2: Build a Sparse Table
	build();
 
	forn(_, q) {
		int a, b;
		cin >> a >> b;
		// answer using sparse table
		int start = loc[a], end = loc[b];
		int k = log2(abs(end-start));
		int ans = pos[k][start];
		if(table[k][end-k+1] < table[k][start]) {
			ans = pos[k][end-k+1];
		}
		ans = who[ans];
 
		// using normal method
		/* int d = euler[start]; */
		/* int ans = who[start]; */
		/* fora(i, start, end+1) { */
		/* 	if(euler[i] < d) { */
		/* 		ans = who[i]; */
		/* 		d = euler[i]; */
		/* 	} */
		/* } */
		cout << ans << endl;
	}
 
 
	return 0;
}