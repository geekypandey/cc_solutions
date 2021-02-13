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

vi v;
bool done=false;

void solve(ll n) {
	ll first = n;
	ll second = n+1;
	ll sum = (first*second)/2;
	if(sum%2 != 0) {
		cout << "NO" << endl;
		return;
	}
	if(first%2 == 0) {
		first = first/2;
		ll end = first/2;
		for(int i = 1; i <= end; i++) {
			v.push_back(second-i);
			v.push_back(i);
		}
	} else {
		second = second/2;
		ll end = second/2;
		for(int i = 0; i < end; i++) {
			if(i) v.push_back(i);
			v.push_back(first-i);
		}
	}
	cout << "YES" << endl;
	cout << v.size() << endl;
	sort(all(v));
	print(v);
	cout << n - v.size() << endl;
	int pos = 0;
	for(int i = 1; i <= n; i++) {
		if(pos < v.size()) {
			if(v[pos] == i) pos++;
			else cout << i << ' ';
		} else {
			cout << i << ' ';
		}
	}
	cout << endl;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	solve(n);

	return 0;
}

