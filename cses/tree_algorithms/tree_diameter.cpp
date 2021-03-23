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

const int mxN = 2e5;

vi adj[mxN+1];
vi de(mxN+1, 0); // represents the maximum distance from current node to its children, tree rooted at 1
int ans = 0;

void dfs(int i, int p=-1) {
	int f=0, s=0;
	for(auto& e: adj[i]) {
		if(e != p) {
			dfs(e, i);
			de[i] = max(de[i], 1+de[e]);
			if(1+de[e] > f) {
				s = f;
				f = 1+de[e];
			} else if(1+de[e] > s) {
				s = 1+de[e];
			}
		}
	}
	ans = max(ans, f+s);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(1); // start the dfs from any node

	cout << ans << endl;
	return 0;
}
