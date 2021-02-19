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
	vi tp(n);
	vi cust(m);
	for(auto& e: tp) cin >> e;
	for(auto& e: cust) cin >> e;

	sort(all(tp));
	set<int> s;
	forn(i, n) s.insert(i);

	for(auto& e: cust) {
		if(s.empty()) {
			cout << -1 << endl;
			continue;
		}
		auto it = upper_bound(all(tp), e);
		it--;
		if(*it > e) {
			cout << -1 << endl;
			continue;
		}
		int pos = distance(begin(tp), it);
		if(s.find(pos) == s.end()) {
			// find a pos before
			auto p = s.upper_bound(pos);
			if(p == s.begin()) {
				cout << -1 << endl;
				continue;
			}
			p--;
			cout << tp[*p] << endl;
			s.erase(*p);
		} else {
			s.erase(pos);
			cout << tp[pos] << endl;
		}
	}

	return 0;
}
