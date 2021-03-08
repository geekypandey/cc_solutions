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
vvi level;
vector<string> v;
int n, m;

bool ok(int i, int j) {
	return (i>=0 && j>=0 && i < n && j < m && v[i][j] != '#');
}

bool ok2(int i, int j) {
	return (i>=0 && j>=0 && i < n && j < m && v[i][j] != '#' && level[i][j] != -1);
}

bool yes=false;
string path, t;
vector<vector<bool>> vis(n, vector<bool>(m, false));

void dfs(int i, int j, char c=' ') {
	if(vis[i][j]) return;
	vis[i][j] = true;
	if(yes) return;
	if(c != ' ') t.PB(c);
	if(i == 0 || i == n-1 || j == 0 || j == m-1) {
		path=t;
		yes=true;
		return;
	}
	if(ok2(i, j+1)) dfs(i, j+1, 'R');
	if(ok2(i, j-1)) dfs(i, j-1, 'L');
	if(ok2(i+1, j)) dfs(i+1, j, 'D');
	if(ok2(i-1, j)) dfs(i-1, j, 'U');
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	v = vector<string>(n);
	level = vvi(n, vi(m, -1));
	vis = vector<vector<bool>>(n, vector<bool>(m, false));

	int ai, aj;
	vector<pi> mon;
	forn(i, n) {
		cin >> v[i];
		forn(j, m) {
			if(v[i][j] == 'A') ai = i, aj=j;
			if(v[i][j] == 'M') mon.PB({i, j});
		}
	}

	queue<pi> qu;
	qu.push({ai, aj});
	int curr = 0;
	while(!qu.empty()) {
		int k = qu.size();
		forn(_, k) {
			int x = qu.front().first, y = qu.front().second; qu.pop();
			if(level[x][y] != -1) continue;
			level[x][y] = curr;
			if(ok(x, y+1)) qu.push({x, y+1});
			if(ok(x, y-1)) qu.push({x, y-1});
			if(ok(x+1, y)) qu.push({x+1, y});
			if(ok(x-1, y)) qu.push({x-1, y});
		}
		curr++;
	}

	for(auto& e: mon) qu.push(e);
	vector<vector<bool>> seen(n, vector<bool>(m, false));
	curr = 0;
	while(!qu.empty()) {
		int k = qu.size();
		forn(_, k) {
			int x = qu.front().first, y = qu.front().second; qu.pop();
			if(seen[x][y]) continue;
			seen[x][y] = true;
			if(level[x][y] >= curr)
				level[x][y] = -1;
			if(ok(x, y+1)) qu.push({x, y+1});
			if(ok(x, y-1)) qu.push({x, y-1});
			if(ok(x+1, y)) qu.push({x+1, y});
			if(ok(x-1, y)) qu.push({x-1, y});
		}
		curr++;
	}

	dfs(ai, aj);
	if(!yes) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << path.size() << endl;
		cout << path << endl;
	}

	return 0;
}
