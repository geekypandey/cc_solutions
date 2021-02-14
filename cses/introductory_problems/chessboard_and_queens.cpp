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

vector<string> v(8);
vector<bool> col(8, false), diag1(16, false), diag2(16, false);
ll counter = 0;

void search(int row) {
	if(row == 8) {
		counter++;
		return;
	}
	for(int i = 0; i < 8; i++) {
		if(v[row][i] == '*' || col[i] || diag1[row+i] || diag2[8-row+i]) continue;
		col[i] = true;
		diag1[row+i]= true;
		diag2[8-row+i] = true;
		search(row+1);
		col[i] = false;
		diag1[row+i] = false;
		diag2[8-row+i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(auto& e: v) cin >> e;
	search(0);
	cout << counter << endl;

	return 0;
}

