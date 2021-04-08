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

vvi adj(mxN);
vi parent(mxN, 0);
vector<map<int, int>> mp(mxN);

void dfs(int i) {
	mp[i][0] = 1;
	for(auto& e: adj[i]) {
		if(e == parent[i]) continue;
		parent[e] = i;
		dfs(e);
		for(auto& [k, v]: mp[e])
			mp[i][k+1] += v;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	if(k == 1) {
		cout << n-1 << endl;
		exit(0);
	}
	dfs(1);

	int ans = 0;
	fora(i, 1, n+1) {
		vi v(n, 0);
		for(auto& e: adj[i]) {
			if(e == parent[i]) continue;
			for(auto& [ke, u]: mp[e]) {
				if(ke <= k-2) // pairing with others
					ans += u*(v[k-2-ke]);
				if(ke == k-1) // straight line pair
					ans += u;
			}
			for(auto& [ke, u]: mp[e]) {
				v[ke]+=u;
			}
		}
	}
	cout << ans << endl;

	return 0;
}

