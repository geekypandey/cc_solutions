#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
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
#define fora(i, a, n) for(ll i = a; i < n; i++)
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

const int M = 1e9+7;
const int mxN = 4e5+1;

vi bit(mxN, 0);
vi v, vals;
int n, q;

void upd(int i, int val) {
	while(i <= mxN) {
		bit[i] += val;
		i += (i&-i);
	}
}

void add(int x, int b) {
	int ind = upper_bound(all(vals), x) - vals.begin();
	upd(ind, b);
}

ll sum(int a) {
	int ind = upper_bound(all(vals), a) - vals.begin();
	ll ans = 0;
	while(ind > 0) {
		ans += bit[ind];
		ind -= (ind&-ind);
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	vi v(n);
	for(auto& e: v) cin >> e;

	vals = v;


	vector<array<int, 3>> rec;
	forn(_, q) {
		char t;
		int a, b;
		cin >> t >> a >> b;
		a--;
		rec.PB({t=='?', a, b});
		if(t == '!')
			vals.PB(b);
	}

	sort(all(vals));
	vals.erase(unique(all(vals)), vals.end()); // used for coordinate compression

	for(auto& e: v) {
		add(e, 1);
	}

	for(auto& e: rec) {
		if(e[0] == 0) {
			// update
			int p = e[1], val = e[2];
			add(v[p], -1);
			v[p] = val;
			add(val, 1);
		} else {
			// query
			int a = e[1], b=e[2];
			cout << sum(b) - sum(a) << endl;
		}
	}

	return 0;
}

