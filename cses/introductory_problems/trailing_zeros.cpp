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

unordered_map<int, int> mp;

int get_count(ll i) {
	if(i%5 != 0) return 0;
	else if(mp.find(i) != mp.end()) return mp[i];
	else return 1 + get_count(i/=5);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	ll ans = 0;
	for(int i = 5; i <= n; i+=5) {
		ans += get_count(i);
	}
	cout << ans << endl;

	return 0;
}

