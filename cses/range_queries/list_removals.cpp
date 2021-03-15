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
int n;
vi v(mxN);
vi t(4*mxN+1, 0);
vi lo(4*mxN+1);
vi hi(4*mxN+1);

void build(int i=1, int l=0, int r=n-1) {
	lo[i] = l;
	hi[i] = r;
	if(l == r) {
		t[i] = 1;
		return;
	}
	int m = l+(r-l)/2;
	build(2*i, l, m);
	build(2*i+1, m+1, r);
	t[i] = t[2*i] + t[2*i+1];
}

void query(int i, int k) {
	if(t[i] == k && (lo[i] == hi[i])) {
		cout << v[lo[i]] << ' ';
		t[i] = 0;
		return;
	}
	if(t[2*i] >= k) {
		query(2*i, k);
	} else {
		query(2*i+1, k-t[2*i]);
	}
	t[i] = t[2*i]+t[2*i+1];
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	forn(i, n) cin >> v[i];

	build();

	forn(_, n) {
		int k;
		cin >> k;
		query(1, k);
	}

	return 0;
}

