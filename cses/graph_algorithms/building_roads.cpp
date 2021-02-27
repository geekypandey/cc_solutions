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

vector<vector<int>> v;
vector<bool> vis;

void dfs(int i) {
	for(auto& e: v[i]) {
		if(vis[e]) continue;
		vis[e] = true;
		dfs(e);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	v = vector<vi>(n+1);
	vis = vector<bool>(n+1, false);

	forn(_, m) {
		int a, b;
		cin >> a >> b;
		v[a].PB(b);
		v[b].PB(a);
	}

	vector<pi> vp;
	int last = 0;
	fora(i, 1, n+1) {
		if(vis[i]) continue;
		if(last) vp.PB(MP(last, i));
		last = i;
		dfs(i);
	}
	cout << vp.size() << endl;
	for(auto& e: vp) {
		cout << e.F << ' ' << e.S << endl;
	}
	return 0;
}
