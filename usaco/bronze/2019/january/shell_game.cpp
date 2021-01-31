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

	setup("shell");

	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(3));

	for(auto& e: v) {
		cin >> e[0] >> e[1] >> e[2];
	}

	// simulate all three conditions
	vector<bool> b(3, false);

	int ans = 0;
	forn(i, 3) {
		b[i] = true;
		int score = 0;
		for(auto& e: v) {
			swap(b[e[0]-1], b[e[1]-1]);
			if(b[e[2]-1]) score++;
		}
		ans = max(ans, score);
		b[0] = b[1] = b[2] = false;
	}
	cout << ans << endl;

	return 0;
}

