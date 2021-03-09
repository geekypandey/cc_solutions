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

int ans=0;
vvi adj;
int n;
vector<bool> vis;

void dfs(int i, int p=-1) {
	for(auto& e: adj[i]) {
		if(e == p) continue;
		dfs(e, i);
		if(!vis[e] && !vis[i]) {
			ans++;
			vis[e] = true;
			vis[i] = true;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	adj = vvi(n);
	vis = vector<bool>(n);

	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(0);
	cout << ans << endl;
	return 0;
}

