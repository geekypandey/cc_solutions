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

bool f(pi a, pi b) {
	if(a.S < b.S) return true;
	else if (a.S > b.S) return false;
	if(a.F <= b.S) return true;
	else return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for(auto& e: v) {
		cin >> e.S >> e.F;
	}

	sort(all(v));
	cout << endl;

	ll ans = 1;
	ll last_count = 1;
	ll start_pos = 1;

	forn(i, n-1) {
		if(start_pos == n) break;
		start_pos = max(i+1, start_pos);
		for(int j = start_pos; j < n; j++) {
			if(v[j].S < v[i].F) start_pos++;
			else break;
		}
		ans = max(ans, start_pos-i);
	}

	cout << ans << endl;
	return 0;
}

