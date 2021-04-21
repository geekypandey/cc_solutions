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

struct Seg {
	const ll ID = LLONG_MIN;
	vl lo, hi, t, delta;

	ll comb(ll a, ll b) {
		return max(a, b);
	}

	void init(int n) {
		lo = vl(4*n+1);
		hi = vl(4*n+1);
		t = vl(4*n+1, 0);
		delta = vl(4*n+1, 0);
		init(1, 0, n-1);
	}

	void init(int i, int l, int r) {
		lo[i] = l;
		hi[i] = r;
		if(l == r) return;
		int m = l+(r-l)/2;
		init(2*i, l, m);
		init(2*i+1, m+1, r);
	}

	void increment(int a, int b, ll val) {
		increment(1, a, b, val);
	}

	void increment(int i, int a, int b, ll val) {
		if(a > hi[i] || b < lo[i]) {
			return;
		}

		if(a<=lo[i] && hi[i]<=b) {
			delta[i] += val;
			return;
		}

		prop(i);
		increment(2*i, a, b, val);
		increment(2*i+1, a, b, val);
		upd(i);
	}

	void prop(int i) {
		delta[2*i] += delta[i];
		delta[2*i+1] += delta[i];
		delta[i] = 0;
	}

	void upd(int i) {
		t[i] = comb(t[2*i] + delta[2*i], t[2*i+1] + delta[2*i+1]);
	}

	ll query(int a, int b) {
		return query(1, a, b);
	}

	ll query(int i, int a, int b) {
		if(b < lo[i] || a > hi[i]) {
			return ID;
		}
		if(a<=lo[i] && hi[i]<=b) {
			return t[i]+delta[i];
		}
		prop(i);
		ll Left = query(2*i, a, b);
		ll Right = query(2*i+1, a, b);
		upd(i);
		return comb(Left, Right);
	}
};


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	Seg st;
	st.init(n);
	vi v(n);
	for(auto& e: v) cin >> e;
	vl ps(n);
	ll sum = 0;
	forn(i, n) {
		sum += v[i];
		ps[i] = sum;
		st.increment(i, i, ps[i]);
	}

	forn(_, q) {
		int t;
		cin >> t;
		if(t == 1) {
			int k, u;
			cin >> k >> u;
			k--;
			st.increment(k, n-1, u-v[k]);
			v[k] = u;
		} else {
			int a, b;
			cin >> a >> b;
			a--, b--;
			ll m = st.query(a, b);
			cout << max(0LL, m - (a-1>=0?st.query(a-1, a-1):0)) << endl;
		}
	}

	return 0;
}
