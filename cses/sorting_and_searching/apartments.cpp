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

	ll n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	vector<bool> taken(m, false);
	for(auto& e: a) cin >> e;
	for(auto& e: b) cin >> e;
	sort(all(a));
	sort(all(b));
	int ans = 0;
	int index = 0;
	for(auto& e: a) {
		while(index < m && b[index] < e-k) index++;
		if(index >= m) break;
		if(b[index] > e+k) continue;
		ans++;
		index++;
	}
	cout << ans << endl;

	return 0;
}

