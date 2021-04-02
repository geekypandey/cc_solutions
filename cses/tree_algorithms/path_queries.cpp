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

const int mxN = 2e5+1;

int n, q;
vi adj[mxN];
vl v(mxN), dist(mxN, 0), sub(mxN, 0);
vi pos(mxN);
int c=1;
vl bit(mxN, 0);

void dfs(int i, int p=0) {
	dist[i] = v[i];
	sub[i] = 1;
	if(p)
		dist[i] += dist[p];
	pos[i] = c++;
	for(auto& e: adj[i]) {
		if(e != p) {
			dfs(e, i);
			sub[i] += sub[e];
		}
	}
}

void upd(int i, ll val) {
	while(i <= n) {
		bit[i] += val;
		i += (i&-i);
	}
}

ll query(int i) {
	ll s = 0;
	while(i > 0) {
		s += bit[i];
		i -= (i&-i);
	}
	return s;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;

	fora(i, 1, n+1) cin >> v[i];

	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(1, 0);

	fora(i, 1, n+1) {
		int p = pos[i];
		upd(p, (ll)dist[i]);
		if(p+1 <= n)
			upd(p+1, (ll)-dist[i]);
	}

	forn(_, q) {
		int t;
		cin >> t;
		if(t == 1) {
			int s, x;
			cin >> s >> x;
			int l = pos[s];
			int r = l+sub[s];
			upd(l, x-v[s]);
			if(r <= n)
				upd(r, v[s]-x);
			v[s] = x;
		} else {
			int s;
			cin >> s;
			int p = pos[s];
			cout << (ll)query(p) << endl;
		}
	}

	return 0;
}
