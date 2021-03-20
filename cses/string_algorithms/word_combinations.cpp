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
	const int p = 27;
	const int M2 = 1e9+23;
	vl p_pow(mxN+1);
	vl d_pow(mxN+1);
	p_pow[0] = 1;
	d_pow[0] = 1;
	fora(i, 1, mxN+1) {
		p_pow[i] = (p_pow[i-1]*p)%M;
		d_pow[i] = (d_pow[i-1]*p)%M2;
	}

	vl ha(n, 0);
	vl hb(n, 0);
	forn(i, n) {
		if(i) {
			ha[i] = (ha[i-1]+(s[i]-'a'+1)*p_pow[i])%M;
			hb[i] = (hb[i-1]+(s[i]-'a'+1)*d_pow[i])%M2;
		} else {
			ha[i] = ((s[i]-'a'+1)*p_pow[i])%M;
			hb[i] = ((s[i]-'a'+1)*d_pow[i])%M2;
		}
	}

	int k;
	cin >> k;
	vector<string> v(k);
	for(auto& e: v) cin >> e;

	sort(all(v), [](auto e, auto f){return e.length() < f.length();});

	vl ah(k, 0);
	vl aj(k, 0);
	forn(i, k) {
		int m = v[i].size();
		forn(j, m) {
			ah[i] = (ah[i] + (v[i][j]-'a'+1)*p_pow[j])%M;
			aj[i] = (aj[i] + (v[i][j]-'a'+1)*d_pow[j])%M2;
		}
	}

	vector<int> dp(n, 0);
	for(int i = 0; i < n; i++) {
		forn(j, k) {
			int m = v[j].length();
			if(m > i+1) break;
			ll cur_h, cur_g;
			if(m == i+1) {
				cur_h = ha[i];
				cur_g = hb[i];
			} else {
				cur_h = (ha[i]-ha[i-m]+M)%M;
				cur_g = (hb[i]-hb[i-m]+M2)%M2;
			}
			bool y = (cur_h == ah[j]*p_pow[i-m+1]%M && (cur_g == aj[j]*d_pow[i-m+1]%M2));
			if(y) {
				if(m == i+1) {
					dp[i]++;
					dp[i] %= M;
				} else {
					dp[i] = (dp[i]+dp[i-m])%M;
				}
			}
		}
	}
	cout << dp[n-1] << endl;


	return 0;
}

