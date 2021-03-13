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

int n, q;
vl t(4*mxN+1);
vi lo(4*mxN+1);
vi hi(4*mxN+1);
vi v(mxN);


void build(int i=1, int l=0, int r=n-1) {
	lo[i] = l;
	hi[i] = r;
	if(l == r) {
		t[i] = v[l];
	} else {
		int m = l+(r-l)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

ll query(int i, int a, int b) {
	if(lo[i] > b || hi[i] < a) {
		return 0;
	}
	if(a<=lo[i] && hi[i]<=b) return t[i];
	return query(2*i, a, b) + query(2*i+1, a, b);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	forn(i, n) cin >> v[i];

	build();

	forn(_, q) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		int i = min(a, b), j = max(a, b);
		cout << query(1, a, b) << endl;
	}


	return 0;
}

