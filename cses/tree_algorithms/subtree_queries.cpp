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

void re(vi& v, int n) {
	forn(i, n) cin >> v[i];
}

// read and write into files, rather than standard i/o
void setup(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

const int M = 1e9+7;

const int mxN = 2e5+1;

vi adj[mxN];
vi v(mxN);
vector<pi> interval(mxN);
vi val;
int n, q;


vl t(4*mxN+1);
vi lo(4*mxN+1);
vi hi(4*mxN+1);

void dfs(int i, int p=-1) {
	interval[i].F = val.size();
	val.PB(v[i]);
	for(auto& e: adj[i]) {
		if(e != p) {
			dfs(e, i);
		}
	}
	interval[i].S = val.size();
	val.PB(v[i]);
}

void build(int i, int l, int r) {
	lo[i] = l;
	hi[i] = r;
	if(l == r) {
		t[i] = val[l];
		return;
	}
	int m = l+(r-l)/2;
	build(2*i, l, m);
	build(2*i+1, m+1, r);
	t[i] = t[2*i] + t[2*i+1];
}

ll query(int i, int l, int r) {
	if(hi[i] < l || lo[i] > r) return 0;
	if(l<=lo[i] && hi[i]<=r) return t[i];
	// update
	t[i] = t[2*i] + t[2*i+1];
	return query(2*i, l, r) + query(2*i+1, l, r);
}

void update(int i, int l, int r, int u) {
	if(hi[i] < l || lo[i] > r) return;
	if(l<=lo[i] && hi[i]<=r) {
		t[i] = u;
		return;
	}
	update(2*i, l, r, u);
	update(2*i+1, l, r, u);
	t[i] = t[2*i] + t[2*i+1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;

	re(v, n);

	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	// pre-order traversal
	dfs(0);


	// build the Segment Tree
	build(1, 0, val.size()-1);

	forn(_, q) {
		int t;
		cin >> t;
		if(t == 1) {
			int s, x;
			cin >> s >> x;
			// update
			s--;
			int l = interval[s].F, r = interval[s].S;
			update(1, l, l, x);
			update(1, r, r, x);
		} else {
			int s;
			cin >> s;
			s--;
			int l = interval[s].F, r = interval[s].S;
			// query
			ll ans = query(1, l, r);
			cout << ans/2 << endl;
		}
	}


	return 0;
}
