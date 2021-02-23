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

	vi a(n), d(n);

	forn(i, n) {
		cin >> a[i] >> d[i];
	}

	sort(all(a));
	sort(all(d));

	ll cur = 0;
	ll ans = 0;
	ll i = 0, j = 0;
	while(i < n && j < n) {
		if(a[i] < d[j]) {
			cur++;
			i++;
		} else {
			cur--;
			j++;
		}
		ans = max(ans, cur);
	}

	cout << ans << endl;
	return 0;
}

