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
vi v(mxN);
vi tmx(4*mxN+1);
vi tmn(4*mxN+1);
vi lo(4*mxN+1);
vi hi(4*mxN+1);

void build(int i = 1, int l = 0, int r=n-1) {
	lo[i] = l;
	hi[i] = r;
	if(l == r) {
		tmx[i] = v[l];
		tmn[i] = v[l];
		return;
	}
	int m = l+(r-l)/2;
	build(2*i, l, m);
	build(2*i+1, m+1, r);
	tmx[i] = max(tmx[2*i], tmx[2*i+1]);
	tmn[i] = min(tmn[2*i], tmn[2*i+1]);
}

void update(int i, int k, int val) {
	if(k < lo[i] || k > hi[i]) {
		return;
	}
	if(lo[i] == k && hi[i] == k) {
		tmx[i] = val;
		tmn[i] = val;
		return;
	}
	update(2*i, k, val);
	update(2*i+1, k, val);
	tmx[i] = max(tmx[2*i], tmx[2*i+1]);
	tmn[i] = min(tmn[2*i], tmn[2*i+1]);
}

ll query(int i, int a, int b) {
	if(a>tmx[i] || b<tmn[i]) {
		return 0L;
	}
	if(a<=tmn[i] && tmx[i]<=b) {
		return hi[i]-lo[i]+1;
	}
	return (long long)query(2*i, a, b) + query(2*i+1, a, b);
}

/* void check(int i=1) { */
/* 	cout << lo[i] << ':' << hi[i] << ' ' << tmx[i] << endl; */
/* 	if(lo[i] == hi[i]) return; */
/* 	check(2*i); */
/* 	check(2*i+1); */
/* } */


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	forn(i, n) cin >> v[i];

	build();

	forn(_, q) {
		char t;
		cin >> t;
		if(t == '!') {
			int k, val;
			cin >> k >> val;
			k--;
			update(1, k, val);
		} else {
			int a, b;
			cin >> a >> b;
			cout << query(1, a, b) << endl;
		}
	}


	return 0;
}

