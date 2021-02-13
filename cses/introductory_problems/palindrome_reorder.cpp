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

	int ch[26] = {0};
	string s;
	cin >> s;

	for(auto& c: s) {
		ch[c-'A']++;
	}

	vector<char> ans;
	int odd_count = 0;
	int odd_pos;

	forn(i, 26) {
		if(ch[i]%2 != 0) {
			odd_count++;
			odd_pos = i;
			continue;
		}
		for(int j = 0; j < ch[i]/2; j++) {
			ans.PB('A'+i);
		}
	}

	if(odd_count > 1) cout << "NO SOLUTION" << endl;
	else {
		for(auto& c: ans) cout << c;
		if(odd_count == 1) {
			for(int i = 0; i < ch[odd_pos]; i++) cout << (char)('A' + odd_pos);
		}
		for(int i = ans.size()-1; i >=0; i--) cout << ans[i];
		cout << endl;
	}

	return 0;
}

