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

vi depth;
vvi adj;

void dfs(int i, int parent, int d=0) {
	depth[i] = d;
	for(auto& e: adj[i]) {
		if(e != parent) dfs(e, i, d+1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	adj = vvi(n);
	depth = vi(n, 0);
	vi deg(n, 0);

	forn(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].PB(b);
		adj[b].PB(a);
		deg[a]++;
		deg[b]++;
	}

	// find the center of the tree
	vi leaves;
	forn(i, n) {
		if(deg[i] <= 1) {
			leaves.PB(i);
		}
	}
	int count = leaves.size();

	while(count < n) {
		vi new_leaves;
		for(auto& node: leaves) {
			for(auto& e: adj[node]) {
				deg[e]--;
				if(deg[e] == 1) new_leaves.PB(e);
			}
			deg[node] = 0;

		}
		count += new_leaves.size();
		leaves = new_leaves;
	}

	// center are in leaves
	if(leaves.size() == 1) { // one center
		int center = leaves.front();
		for(auto& e: adj[center]) {
			dfs(e, center, 1);
		}
		int d = *max_element(all(depth));
		for(auto& e: depth) {
			cout << e + d << ' ';
		}
	} else { // two centers
		int c1 = leaves.front();
		int c2 = leaves.back();
		dfs(c1, c2);
		dfs(c2, c1);
		int d = *max_element(all(depth));
		for(auto& e: depth) {
			cout << e + d + 1 << ' ';
		}
	}
	return 0;
}

