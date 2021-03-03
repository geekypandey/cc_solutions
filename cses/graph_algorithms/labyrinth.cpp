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


int n, m;
vector<string> v;
vector<vector<bool>> vis;

bool ok(int i, int j) {
	return (i>=0 && j>=0 && i<n && j<m && v[i][j] != '#' && !vis[i][j]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	v = vector<string>(n);

	for(auto& e: v) cin >> e;

	// find position to start the bfs
	int x, y;
	forn(i, n) {
		forn(j, m) {
			if(v[i][j] == 'A') {
				x = i;
				y = j;
			}
		}
	}

	vis = vector<vector<bool>>(n, vector<bool>(m, false));
	vector<vector<char>> p(n, vector<char>(m, ' '));

	deque<pi> dq;
	bool done = false;
	dq.PB(MP(x, y));

	while(!dq.empty() && !done) {
		int n = dq.size();
		forn(_, n) {
			auto pa = dq.front();
			dq.pop_front();
			vis[pa.F][pa.S] = true;
			if(v[pa.F][pa.S] == 'B') {
				x = pa.F;
				y = pa.S;
				done=true;
				break;
			}
			if(ok(pa.F, pa.S+1)) {
				dq.PB(MP(pa.F, pa.S+1));
				p[pa.F][pa.S+1] = 'R';
			}
			if(ok(pa.F, pa.S-1)) {
				dq.PB(MP(pa.F, pa.S-1));
				p[pa.F][pa.S-1] = 'L';
			}
			if(ok(pa.F+1, pa.S)) {
				dq.PB(MP(pa.F+1, pa.S));
				p[pa.F+1][pa.S] = 'D';
			}
			if(ok(pa.F-1, pa.S)) {
				dq.PB(MP(pa.F-1, pa.S));
				p[pa.F-1][pa.S] = 'U';
			}
		}
	}
	if(done) {
		cout << "YES" << endl;
		string ans;
		while(v[x][y] != 'A') {
			char c = p[x][y];
			ans.PB(c);
			if(c == 'L') y++;
			else if(c == 'R') y--;
			else if(c == 'U') x++;
			else if(c == 'D') x--;
		}
		cout << ans.length() << endl;
		reverse(all(ans));
		cout << ans << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}

