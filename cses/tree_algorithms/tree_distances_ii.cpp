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
int n;
vi adj[mxN];
long long sub_size[mxN], total_depth[mxN];


// count and depth
pair<int, ll> dfs(int i, int p=-1) {
	ll sum = 0; // keeps the track of sum of depths below
	int count = 1; // keep track of subtree size (includes itself)
	for(auto& e: adj[i]) {
		if(e != p) {
			auto p = dfs(e, i);
			sum += p.S + sub_size[e];
			count += p.F;
		}
	}

	total_depth[i] = sum;
	sub_size[i] = count; // sub_size includes itself
	return {count, sum}; // one for itself
}

void dfs2(int i, int p=-1) {
	if(p!=-1) {
		total_depth[i] = total_depth[p] - sub_size[i] + (n-sub_size[i]);
	}
	for(auto& e: adj[i]) {
		if(e != p) {
			dfs2(e, i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	forn(i, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(1);
	dfs2(1);
	fora(i, 1, n+1) cout << total_depth[i] << ' ';
	cout << endl;

	return 0;
}
