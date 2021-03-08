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

	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<pair<int, int>>> adj(n+1);

	forn(_, m) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].PB({b, w});
		adj[b].PB({a, w});
	}

	vvl d(n+1, vl(n+1, LLONG_MAX));
	fora(i, 1, n+1) {
		d[i][i] = 0;
		priority_queue<pi> qu;
		qu.push({0, i});
		vector<bool> vis(n+1, false);
		while(!qu.empty()) {
			int a = qu.top().second; qu.pop();
			if(vis[a]) continue;
			vis[a] = true;
			for(auto& e: adj[a]) {
				ll b = e.F, w = e.S;
				if(d[i][b] > d[i][a] + w) {
					d[i][b] = d[i][a] + w;
					qu.push({-d[i][b], b});
				}
			}
		}
	}

	forn(_, q) {
		int a, b;
		cin >> a >> b;
		cout << (d[a][b] == LLONG_MAX?-1:d[a][b]) << endl;
	}

	return 0;
}

