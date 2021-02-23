#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
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

ll cal(vi v, ll val) {
	ll ans = 0;
	for(auto& e: v) ans += abs(val-e);
	return ans;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	vi v(n);
	for(auto& e: v) cin >> e;

	auto p = minmax_element(all(v));
	ll start = *p.F;
	ll end = *p.S;

	ll m;
	while(start <= end) {
		m = start + (end-start)/2L;
		if(cal(v, m) < cal(v, m-1) && (cal(v, m) > cal(v, m+1))) {
			start = m+1;
		} else if(cal(v, m) > cal(v, m-1) && (cal(v, m) < cal(v, m+1))) {
			end = m-1;
		} else break;
	}
	cout << cal(v, m) << endl;
	return 0;
}
