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
#define T ll tt; cin >> tt; while(tt--)


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

	T {
		ll row, col;
		cin >> row >> col;
		if(row > col) {
			if(row%2 == 0) {
				cout << (row*row) - (col-1);
			} else {
				cout << (row-1)*(row-1) + 1 + (col-1);
			}
		} else {
			if(col%2 != 0) {
				cout << (col*col) - (row-1);
			} else {
				cout << (col-1)*(col-1) + 1 + (row-1);
			}
		}
		cout << endl;
	}

	return 0;
}

