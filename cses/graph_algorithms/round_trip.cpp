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
int n, m;
vvi adj;
vector<bool> vis;
vector<int> path;
vector<bool> done;

void dfs(int i, int j) {
	path.PB(i+1);
	vis[i] = true;
	done[i] = true;
	for(auto& e: adj[i]) {
		if(vis[e]) {
			if(e != j) {
				reverse(all(path));
				vi v;
				v.PB(e+1);
				for(auto& el: path) {
					v.PB(el);
					if(el == e+1) break;
				}
				cout << v.size() << endl;
				print(v);
				exit(0);
			}
		} else {
			dfs(e, i);
		}
	}

	path.pop_back();
	vis[i] = false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	adj = vvi(n);
	vis = vector<bool>(n, false);
	done = vector<bool>(n, false);

	forn(_, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	forn(i, n) {
		if(!done[i]) dfs(i, -1);
	}
	cout << "IMPOSSIBLE" << endl;

	return 0;
}
