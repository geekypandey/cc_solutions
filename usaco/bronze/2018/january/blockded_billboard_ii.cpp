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

struct Rect {
	int x1, y1, x2, y2;
	Rect() {
		cin >> x1 >> y1 >> x2 >> y2;
	}

	int overlap(Rect y) {
		int x_overlap = max(0, min(x2, y.x2)-max(x1, y.x1));
		int y_overlap = max(0, min(y2, y.y2)-max(y1, y.y1));
		return x_overlap*y_overlap;
	}

	int area() {
		return (x2-x1)*(y2-y1);
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	setup("billboard");
	Rect a, b;
	if(b.y1<=a.y1 && a.y2<=b.y2) cout << a.area() - a.overlap(b);
	else if(b.x1<=a.x1 && a.x2<=b.x2) cout << a.area() - a.overlap(b);
	else cout << a.area();

	return 0;
}

