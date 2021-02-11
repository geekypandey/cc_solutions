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

	setup("mixmilk");

	vector<vector<int>> v(3, vector<int>(2));

	for(auto& e: v) {
		cin >> e[0] >> e[1];
	}

	forn(i, 100) {
		int curr = i%3;
		int next = (i+1)%3;
		v[next][1] += v[curr][1];
		v[curr][1] = max(0, v[next][1]-v[next][0]);
		v[next][1] -= v[curr][1];
	}

	cout << v[0][1] << endl;
	cout << v[1][1] << endl;
	cout << v[2][1] << endl;

	return 0;
}
