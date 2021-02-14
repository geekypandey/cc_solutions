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


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vi v(n);

	ll sum = 0;
	for(auto& e: v) { cin >> e; sum+=e; }
	if(n == 1) {cout << v.front() << endl; return 0;}

	ll ans = 1e9+1;
	for(int i = 1; i < pow(2, n)-1; i++) {
		ll curr = 0;
		for(int j = 0; j < n; j++) {
			if(((1<<j)&i) > 0) curr += v[j];
		}
		ans = min(ans, abs(curr-(sum-curr)));
	}
	cout << ans << endl;

	return 0;
}

