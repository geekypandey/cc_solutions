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

	int n, m;
	cin >> n >> m;

	vvi v(n+1);

	forn(_, m) {
		int a, b;
		cin >> a >> b;
		v[a].PB(b);
		v[b].PB(a);
	}

	vector<bool> vis(n+1, false);
	vi parent(n+1, -1);

	queue<int> qu;
	qu.push(1);
	vis[1] = true;
	while(!qu.empty()) {
		int p = qu.front(); qu.pop();
		for(auto& e: v[p]) {
			if(vis[e]) continue;
			vis[e] = true;
			parent[e] = p;
			qu.push(e);
		}
	}
	if(parent[n] == -1) cout << "IMPOSSIBLE" << endl;
	else {
		int pos = n;
		vi ans;
		ans.PB(n);
		while(pos != 1) {
			ans.PB(parent[pos]);
			pos = parent[pos];
		}
		reverse(all(ans));
		cout << ans.size() << endl;
		print(ans);
	}

	return 0;
}

