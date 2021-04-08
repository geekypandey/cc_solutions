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
int n, q;
vi t;
vvi table;

void build() {
	int max_k = log2(1e9);
	table = vvi(n, vi(max_k+1, -1));

	forn(i, n) table[i][0] = t[i]-1;
	fora(k, 1, max_k+1) {
		forn(i, n) {
			if(table[i][k-1] != -1)
				table[i][k] = table[table[i][k-1]][k-1];
		}
	}
}

int jump(int a, int d) {
	int max_k = log2(1e9);
	forn(i, max_k+1) {
		if(d & (1<<i)) a = table[a][i];
	}
	return a;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	t = vi(n);
	forn(i, n) cin >> t[i];
	build();
	forn(_, q) {
		int x, k;
		cin >> x >> k;
		x--;
		cout << jump(x, k)+1 << endl;
	}

	return 0;
}

