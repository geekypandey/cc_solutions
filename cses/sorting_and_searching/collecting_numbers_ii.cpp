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
#define fora(i, a, b) for(ll i = a; i < b; i++)
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

	vi v(n);
	vi big(n, true);
	for(auto& e: v) cin >> e;

	vi p(n);
	forn(i, n) {
		p[v[i]-1] = i;
	}

	fora(i, 1, n) {
		if(p[i] < p[i-1]) big[i]=0;
	}

	int count = 0;
	for(auto& e: big) {
		count += (!e);
	}

	forn(_, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		int f=v[a], s=v[b];
		swap(v[a], v[b]);
		f--, s--;
		// check if the value of false
		swap(p[f], p[s]);
		bool prev = big[f];
		bool cur = true;
		if(f) cur = p[f]>p[f-1];
		if(prev != cur) {
			if(cur) count--;
			else count++;
		}
		big[f] = cur;
		if(f+1 < n) {
			prev = big[f+1];
			cur = p[f+1]>p[f];
			if(prev != cur) {
				if(cur) count--;
				else count++;
			}
			big[f+1] = cur;
		}

		prev = big[s];
		cur = true;
		if(s) cur = p[s]>p[s-1];
		if(prev != cur) {
			if(cur) count--;
			else count++;
		}
		big[s] = cur;
		if(s+1 < n) {
			prev = big[s+1];
			cur = p[s+1]>p[s];
			if(prev != cur) {
				if(cur) count--;
				else count++;
			}
			big[s+1] = cur;
		}

		cout << count+1 << endl;
	}

	return 0;
}

