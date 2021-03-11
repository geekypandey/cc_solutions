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
vi temp;
vi boss[mxN];
vi adj[mxN];

void dfs(int i) {
	boss[i] = temp;
	temp.PB(i);
	for(auto& e: adj[i]) {
		dfs(e);
	}
	temp.pop_back();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	fora(i, 2, n+1) {
		int b;
		cin >> b;
		adj[b].PB(i);
	}
	dfs(1);

	forn(_, q) {
		int x, k;
		cin >> x >> k;
		int n = boss[x].size();
		if(n < k) cout << -1 << endl;
		else cout << boss[x][n-k] << endl;
	}

	return 0;
}

