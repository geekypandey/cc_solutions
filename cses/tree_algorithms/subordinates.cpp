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

vvi adj;
vi v;
int n;

void dfs(int i=1) {
	v[i] = 1;
	for(auto& e: adj[i]) {
		dfs(e);
		v[i] += v[e];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	adj = vvi(n+1);
	v = vi(n+1, 0);

	fora(i, 2, n+1) {
		int num;
		cin >> num;
		adj[num].PB(i);
	}

	dfs();
	fora(i, 1, n+1) cout << v[i]-1 << ' ';

	return 0;
}

