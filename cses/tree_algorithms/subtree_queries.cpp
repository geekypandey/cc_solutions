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
int c = 1;
int n, q;
vl bit(2*mxN+1);

void upd(int i, int val) {
	while(i <= 2*n) {
		bit[i] += val;
		i += (i&-i);
	}
}

ll sum(int i) {
	ll total = 0;
	while(i > 0) {
		total += bit[i];
		i -= (i&-i);
	}
	return total;
}

ll sum(int l, int r) {
	return sum(r) - sum(l-1);
}

void dfs(int i, int p=-1) {
	interval[i].F = c++;
	upd(interval[i].F,  v[i]);
	for(auto& e: adj[i]) {
		if(e != p) {
			dfs(e, i);
		}
	}
	interval[i].S = c++;
	upd(interval[i].S, v[i]);
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


	forn(_, q) {
		int t;
		cin >> t;
		if(t == 1) {
			int s, x;
			cin >> s >> x;
			// update
			s--;
			int l = interval[s].F, r = interval[s].S;
			upd(l, x-v[s]);
			upd(r, x-v[s]);
			v[s] = x;
		} else {
			int s;
			cin >> s;
			s--;
			int l = interval[s].F, r = interval[s].S;
			// query
			ll ans = sum(l, r);
			cout << ans/2 << endl;
		}
	}


	return 0;
}
