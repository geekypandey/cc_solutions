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

bool check(int r, int c, int n) {
	if(r >= 0 && r < n && c>=0 && c < n) return true;
	return false;
}

ll get_count(int n) {
	ll ans = 0;
	forn(r, n) {
		forn(c, n) {
			ll count = 0;
			if(check(r+1, c-2, n)) count++;
			if(check(r+1, c+2, n)) count++;
			if(check(r+2, c-1, n)) count++;
			if(check(r+2, c+1, n)) count++;
			ans = ans + (n-c-1) + (n-r-1)*n - count;
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cout << get_count(i) << endl;
	}

	return 0;
}

