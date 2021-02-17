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


int solve(ll k) {

	ll counts = 9;
	ll size = 1;
	ll start = 0;
	while(k-counts*size >= 0) {
		k -= counts*size;
		start += counts;
		counts *= 10;
		size+=1;
	}
	ll div = k/size;
	ll rem = k%size;
	if(div != 0) {
		start += div;
		if(rem == 0) return start%10;
		else {
			start += 1;
			ll pos = size-rem;
			start /= powl(10, pos);
			return start%10;
		}
	} else {
		if(rem == 0) return start%10;
		else {
			start +=1;
			ll pos = size-rem;
			start /= powl(10, pos);
			return start%10;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T {
		ll k;
		cin >> k;
		/* if(k <= 9) cout << k << endl; */
		/* else */
		cout << solve(k) << endl;
	}

	return 0;
}
