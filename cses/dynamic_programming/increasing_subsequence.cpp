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
vi v, vals;
int n;

vi t(4*mxN+1);
vi lo(4*mxN+1);
vi hi(4*mxN+1);

void build(int i=1, int l = 0, int r=n-1) {
	lo[i] = l;
	hi[i] = r;
	if(l == r) {
		t[i] = 0;
		return;
	}
	int m = l+(r-l)/2;
	build(2*i, l, m);
	build(2*i+1, m+1, r);
}

void upd(int i, int k, int val) {
	if(lo[i] > k || hi[i] < k) {
		return;
	}
	if(k<=lo[i] && hi[i]<=k) {
		t[i] = max(t[i], val);
		return;
	}
	upd(2*i, k, val);
	upd(2*i+1, k, val);
	t[i] = max(t[2*i], t[2*i+1]);
}

int query(int i, int l, int r) {
	if(lo[i] > r || hi[i] < l) {
		return INT_MIN;
	}
	if(l<=lo[i] && hi[i]<=r) {
		return t[i];
	}
	return max(query(2*i, l, r), query(2*i+1, l, r));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	v = vector<int>(n);
	for(auto& e: v) cin >> e;
	v.erase(unique(all(v)), v.end());
	n = v.size();
	vals = v;
	sort(all(vals));
	vals.erase(unique(all(vals)), vals.end());
	n = vals.size();
	build();

	int ans = 0;
	for(auto& e: v) {
		int ind = upper_bound(all(vals), e) - vals.begin();
		int q = query(1, 0, ind-1);
		upd(1, ind, q+1);
		ans = max(ans, q+1);
	}
	cout << ans << endl;

	return 0;
}
