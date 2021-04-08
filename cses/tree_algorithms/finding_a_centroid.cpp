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

const int mxN=2e5+1;

vi adj[mxN], parent(mxN, 0), sub(mxN);


void dfs(int i) {
	sub[i] = 1;
	for(auto& e: adj[i]) {
		if(e == parent[i]) continue;
		parent[e] = i;
		dfs(e);
		sub[i] += sub[e];
	}
}

int ans;
int n;

void dfs2(int i) {
	int m = 0;
	int node;
	for(auto& e: adj[i]) {
		if(e == parent[i]) continue;
		if(sub[e] > m) {
			m = sub[e];
			node = e;
		}
	}
	if(m <= n/2) {
		ans = i;
		return;
	} else {
		dfs2(node);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(1);
	dfs2(1);

	cout << ans << endl;
	return 0;
}
