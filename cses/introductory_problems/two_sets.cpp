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

// -1 means negative value
// 0 means try next value
int build(ll n, ll sum) {
	if(sum < 0) return -1;
	if(sum == 0) {
		done=true;
		return 1;
	}

	int start=1;
	if(!v.empty())
		start = v.back()+1;

	for(int i = start; i < n; i++) {
		v.PB(i);
		int val = build(n, sum-i);
		if(done) break;
		v.pop_back();
		if(val == -1) {
			return 0;
		}
	}
	return 0;
}

void solve(ll n) {
	ll sum = (n*(n+1))/2;
	if(sum%2 != 0) {
		cout << "NO" << endl;
		return;
	}
	sum /= 2;
	build(n, sum);
	if(!done){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	cout << v.size() << endl;
	print(v);
	cout << n - v.size() << endl;
	int pos = 0;
	for(int i = 1; i <= n; i++) {
		if(pos < v.size()) {
			if(v[pos] != i) cout << i << ' ';
			else pos++;
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

