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

vi bit(mxN+1, 0);

void upd(int i) {
	int ind = upper_bound(all(vals), i) - vals.begin();
	while(ind <= n) {
		bit[ind] += 1;
		ind += (ind&-ind);
	}
}

int query(int i) {
	int ind = upper_bound(all(vals), i) - vals.begin();
	int s = 0;
	while(ind > 0) {
		s += bit[ind];
		ind -= (ind&-ind);
	}
	return s;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	v = vector<int>(n);
	for(auto& e: v) cin >> e;
	v.erase(unique(all(v)), v.end());
	vals = v;
	sort(all(vals));
	print(v);

	n = v.size();
	int ans = 0;
	for(auto& e: v) {
		upd(e);
		int q = query(e);
		cout << e << ' ' << q << endl;
		ans = max(ans, q);
	}
	cout << ans << endl;

	return 0;
}
