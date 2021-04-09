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

int n, k1, k2;
ll ans = 0;
vvi adj(mxN);
vi sub(mxN, 0);
vi t(mxN, 0);
vector<bool> processed(mxN, false);
int cnt[200001]{1}, mx_depth;

void upd(int i, int val) {
	while(i <= n) {
		t[i] += val;
		i += (i&-i);
	}
}

int sum(int i) {
	int s = 0;
	while(i > 0) {
		s += t[i];
		i -= (i&-i);
	}
	return s;
}

int query(int a, int b) {
	if(a == b && a == 0) return 1;
	return sum(b) - sum(max(0, a-1)) + (a==0?1:0);
}

int get_subtree_size(int i, int p = -1) {
	sub[i] = 1;
	for(auto& e: adj[i]) if(!processed[e] && e != p)
		sub[i] += get_subtree_size(e, i);
	return sub[i];
}

int get_centroid(int i, int p, int n) {
	for(auto& e: adj[i]) {
		if(!processed[e] && e != p && sub[e] > n/2)
			return get_centroid(e, i, n);
	}
	return i;
}

void get_cnt(int i, int p, bool filling, int d = 1) {
	if(d > k2) return;
	mx_depth = max(mx_depth, d);
	if(filling) {
		upd(d, 1);
	}
	else {
		int ka = max(0, k1-d);
		int kb = k2-d;
		ans += query(ka, kb);
	}
	for(auto& e: adj[i]) if(!processed[e] && e != p)
		get_cnt(e, i, filling, d+1);
}

void centroid_decomp(int i = 1) {
	int centroid = get_centroid(i, -1, get_subtree_size(i));
	processed[centroid] = true;
	mx_depth = 0;
	for(auto& e: adj[centroid]) if(!processed[e]) {
		get_cnt(e, centroid, false);
		get_cnt(e, centroid, true);
	}
	fora(i, 1, mx_depth+1) upd(i, -query(i, i));
	for(auto& e: adj[centroid]) if(!processed[e]) centroid_decomp(e);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k1 >> k2;
	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	centroid_decomp();
	cout << ans;

	return 0;
}
