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
const int mxN = 1001;
string v[mxN], p[mxN];

bool ok(int i, int j) {
	return (i>=0 && j>=0 && i<n && j<m && (v[i][j] == '.'));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	int si, sj, ti, tj;
	forn(i, n) {
		cin >> v[i];
		forn(j, m) {
			if(v[i][j] == 'A')
				si = i, sj = j;
			if(v[i][j] == 'B')
				ti = i, tj = j, v[i][j]='.';
		}
		p[i]= string(m, 0);
	}

	queue<array<int, 2>> qu;
	qu.push({si, sj});

	const int di[4] = {1, 0, -1 , 0}, dj[4] = {0, 1, 0, -1};
	const char d[4] = {'D', 'R', 'U', 'L'};
	while(!qu.empty()) {
		auto pa = qu.front();
		qu.pop();
		if(pa[0] == ti && pa[1] == tj) break;
		forn(i, 4) {
			int ni = pa[0] + di[i], nj=pa[1]+dj[i];
			if(ok(ni, nj)) {
				v[ni][nj] = '#';
				qu.push({ni, nj});
				p[ni][nj] = d[i];
			}
		}
	}

	if(p[ti][tj]) {
		cout << "YES" << endl;
		string ans;
		while((ti != si) || (tj != sj)) {
			char c = p[ti][tj];
			ans.PB(c);
			if(c == 'L') tj++;
			if(c == 'R') tj--;
			if(c == 'U') ti++;
			if(c == 'D') ti--;
		}
		reverse(all(ans));
		cout << ans.length() << endl;
		cout << ans << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}

