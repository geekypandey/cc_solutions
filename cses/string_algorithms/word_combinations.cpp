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
unordered_map<char, vector<string>> mp;
int ans = 0;

void dfs(string s, int i = 0) {
	int n = s.size();
	if(i == n) {
		ans++;
		ans = ans%M;
		return;
	}
	for(auto& e: mp[s[i]]) {
		if(e.size() > n-i+1) continue;
		int m = e.size();
		bool yes = true;
		for(int j = 0; j < m; j++) {
			if(e[j] != s[i+j]) {
				yes=false;
			}
		}
		if(yes) dfs(s, i+m);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n;
	cin >> n;
	forn(_, n) {
		string t;
		cin >> t;
		mp[t[0]].PB(t);
	}
	dfs(s);
	cout << ans << endl;

	return 0;
}

