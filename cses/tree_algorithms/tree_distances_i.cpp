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

const int mxN = 2e5;
vi adj[mxN+1];
vi de(mxN+1, 0);
int max_depth = 0;

void dfs(int i, int p=-1, int d=0) {
	de[i] = d;
	for(auto& e: adj[i]) {
		if(e == p) continue;
		dfs(e, i, d+1);
	}
	max_depth = max(max_depth, d);
}

vi ans(mxN+1);

void dfs2(int i, int p, int m) {
	ans[i] = de[i]+m+1;
	for(auto& e: adj[i]) {
		if(e != p) dfs2(e, i, m);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vi con(n+1, 0);
	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
		con[a]++;
		con[b]++;
	}

	vi leaves;
	fora(i, 1, n+1) {
		if(con[i] <= 1) {
			con[i]--;
			leaves.PB(i);
		}
	}

	int count = leaves.size();
	vector<bool> vis(n+1, false);

	// finding the center

	while(count < n) {
		vi new_leaves;
		for(auto& leaf: leaves) {
			for(auto& e: adj[leaf]) {
				if(vis[e]) continue;
				con[e]--;
				if(con[e] == 1) new_leaves.PB(e);
			}
			vis[leaf] = true;
		}
		count += new_leaves.size();
		leaves = new_leaves;
	}

	// one center
	if(leaves.size() == 1) {
		int root = leaves[0];
		dfs(root);
		fora(i, 1, n+1) {
			cout << max_depth + de[i] << ' ';
		}
	} else {
		int f_root = leaves[0], s_root = leaves[1];
		int f_max, s_max;
		dfs(f_root, s_root, 0);
		f_max = max_depth;
		max_depth = 0;
		dfs(s_root, f_root, 0);
		s_max = max_depth;
		dfs2(f_root, s_root, f_max);
		dfs2(s_root, f_root, s_max);
		fora(i, 1, n+1) cout << ans[i] << ' ';
	}


	return 0;
}

