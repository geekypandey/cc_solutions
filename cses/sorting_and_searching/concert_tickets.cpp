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

	ll n, m;
	cin >> n >> m;
	vector<bool> used(n, false);
	vi tp(n);
	vi cust(m);
	for(auto& e: tp) cin >> e;
	for(auto& e: cust) cin >> e;

	sort(all(tp));

	for(auto& e: cust) {
		auto it = lower_bound(all(tp), e+1);
		int pos = distance(begin(tp), it);
		if(pos == n) pos--;
		while(pos > 0 && (used[pos] == true || tp[pos] > e)) {
			pos--;
		}
		if(used[pos] == false && tp[pos] <= e) {
			used[pos] = true;
			cout << tp[pos] << endl;
		}
		else cout << -1 << endl;
	}


	return 0;
}

