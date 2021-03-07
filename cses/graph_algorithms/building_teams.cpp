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
vi color;
bool yes=true;

void dfs(int i, bool val) {
	if(color[i] != -1) {
		return;
	}
	color[i] = val;
	for(auto& e: adj[i]) {
		if(color[e] == val) yes=false;
		dfs(e, !val);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	adj = vvi(n+1);
	color = vi(n+1, -1);

	forn(_, m) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	fora(i, 1, n+1) {
		if(color[i] == -1) dfs(i, true);
	}
	if(yes) {
		fora(i, 1, n+1) {
			int e = color[i];
			if(e == -1) cout << 1 << ' ';
			else cout << e+1 << ' ';
		}
	} else cout << "IMPOSSIBLE" << endl;



	return 0;
}

