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

ll n, q;
vl adj[mxN];
vl v(mxN), sub(mxN, 0), de(mxN, 0);
vl pos(mxN), heavy(mxN, -1), head(mxN, -1), parent(mxN, 0);
vl bit(mxN, 0);
ll c = 1;

void dfs(ll i, ll p=0) {
	sub[i] = 1;
	ll max_sub = 0;
	for(auto& e: adj[i]) {
		if(e != p) {
			de[e] = de[i] +1;
			parent[e] = i;
			dfs(e, i);
			sub[i] += sub[e];
			if(sub[e] > max_sub) {
				max_sub = sub[e];
				heavy[i] = e;
			}
		}
	}
}

void upd(ll i, ll val) {
	while(i <= n) {
		bit[i] += val;
		i += (i&-i);
	}
}

void build_hld(ll i, ll h) {
	head[i] = h;
	pos[i] = c++;
	upd(pos[i], v[i]);
	if(heavy[i] != -1)
		build_hld(heavy[i], h);
	for(auto& e: adj[i]) {
		if(e != parent[i] && e != heavy[i]) {
			build_hld(e, e);
		}
	}
}

ll sum(ll i) {
	ll s=0;
	while(i > 0) {
		s+= bit[i];
		i-=(i&-i);
	}
	return s;
}

ll sum(ll l, ll r) {
	return sum(r) - sum(l-1);
}

ll query(ll i) {
	ll ans = 0;
	while(head[i] != head[1]) {
		ll h = head[i];
		ll l = pos[h];
		ll r = l + de[i] - de[h];
		ans += sum(l , r);
		i = parent[h];
	}
	ll h = head[i];
	ll l = pos[h] + de[1] - de[h];
	ll r = pos[h] + de[i] - de[h];
	ans += sum(l, r);
	return ans;
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

	dfs(1);

	build_hld(1, 1);

	forn(_, q) {
		ll t;
		cin >> t;
		if(t == 1) {
			ll s, x;
			cin >> s >> x;
			ll p = pos[s];
			upd(p, (ll)x-v[s]);
			v[s] = p;
		} else {
			ll s;
			cin >> s;
			cout << (ll)query(s) << endl;
		}
	}

	return 0;
}
