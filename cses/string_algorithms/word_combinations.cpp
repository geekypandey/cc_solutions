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
const int mxN = 1e6;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.length();

	// hashing the string s
	const int p = 31;
	vl p_pow(mxN+1);
	p_pow[0] = 1;
	fora(i, 1, mxN+1) {
		p_pow[i] = (p_pow[i-1]*p)%M;
	}


	vl h(n, 0);
	forn(i, n) {
		if(i)
			h[i] = (h[i-1]+(s[i]-'a'+1)*p_pow[i])%M;
		else
			h[i] = ((s[i]-'a'+1)*p_pow[i])%M;
	}
	print(h);

	int k;
	cin >> k;
	vector<string> v(k);
	for(auto& e: v) cin >> e;

	sort(all(v), [](auto e, auto f){return e.length() < f.length();});

	vl ah(k, 0);
	forn(i, k) {
		int m = v[i].size();
		forn(j, m) {
			ah[i] = (ah[i] + (v[i][j]-'a'+1)*p_pow[j])%M;
		}
	}
	print(ah);

	vector<int> dp(n, 0);
	for(int i = 0; i < n; i++) {
		forn(j, k) {
			int m = v[j].length();
			if(m > i+1) break;
			ll cur_h;
			if(m != (i+1))
				cur_h = (h[i] - (h[i-m]+M))%M;
			else
				cur_h = h[i];
			bool y = (cur_h == (ah[j]*p_pow[i])%M);
			if(y) {
				cout << "here" << endl;
				if(m != i+1) {
					dp[i] = (dp[i]+dp[i-m])%M;
				} else {
					dp[i]++;
					dp[i]%=M;
				}
			}
		}
	}
	print(dp);
	cout << dp[n-1] << endl;


	return 0;
}

