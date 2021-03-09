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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vvi adj(n);
	vi deg(n);
	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].PB(b);
		adj[b].PB(a);
		deg[a]++;
		deg[b]++;
	}
	vector<pi> v;
	vector<bool> vis(n+1);
	forn(i, n) {
		v.PB({deg[i], i});
	}
	sort(all(v));
	int ans = 0;
	for(auto& node: v) {
		auto a = node.S;
		if(vis[a]) continue;
		vis[a] = true;
		for(auto& e: adj[a]) {
			if(!vis[e]) {
				ans++;
				vis[e] = true;
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}

