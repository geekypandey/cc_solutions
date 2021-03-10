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

vvi adj;
int n;
int ans = 1;

int dfs(int i, int p=-1) {
	vi depth;
	for(auto& e: adj[i]) {
		if(e != p) depth.PB(dfs(e, i));
	}
	if(depth.empty()) return 1;
	// this is the top node from where the diameter is passing
	sort(all(depth));
	if(depth.size() > 1) {
		int k = depth.size();
		ans = max(ans, depth[k-1]+depth[k-2]+1);
		return depth.back() + 1;
	}
	ans = max(ans, depth.back()+1);
	return depth.back() + 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	adj = vvi(n);

	forn(_, n-1) {
		int a, b;
		cin >> a >> b; a--, b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(0);
	// ans is the number of nodes in the diameter path
	cout << ans-1 << endl;

	return 0;
}
