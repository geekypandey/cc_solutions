#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define PB push_back
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, b) for(int i = a; i < b; i++)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

const int mxN = 2e5+1;
int n, q;
vvi adj(mxN);
vi v(mxN);
vi t(4*mxN+1);
vi lo(4*mxN+1);
vi hi(4*mxN+1);
vi parent(mxN, 0), heavy(mxN, 0), head(mxN), pos(mxN), sub(mxN), de(mxN, 0);
vi val(mxN, 0);
int c = 0;

void build(int i, int l, int r) {
	lo[i] = l;
	hi[i] = r;
	if(l == r) {
		t[i] = val[l];
		return;
	}
	int m = l + (r-l)/2;
	build(2*i, l, m);
	build(2*i+1, m+1, r);
	t[i] = max(t[2*i], t[2*i+1]);
}

void dfs(int i) {
	sub[i] = 1;
	int max_sub = 0;
	for(auto& e: adj[i]) {
		if(e == parent[i]) continue;
		de[e] = de[i] + 1;
		parent[e] = i;
		dfs(e);
		sub[i] += sub[e];
		if(sub[e] > max_sub) {
			max_sub = sub[e];
			heavy[i] = e;
		}
	}
}

void build_hld(int i, int h) {
	head[i] = h;
	pos[i] = c++;
	val[pos[i]] = v[i];
	if(heavy[i])
		build_hld(heavy[i], h);
	for(auto& e: adj[i]) {
		if(e != parent[i] && e != heavy[i])
			build_hld(e, e);
	}
}

void upd(int i, int l, int r, int val) {
	if(lo[i]>r || hi[i] < l)
		return;
	if(l<=lo[i] && hi[i]<=r) {
		t[i] = val;
		return;
	}
	upd(2*i, l, r, val);
	upd(2*i+1, l, r, val);
	t[i] = max(t[2*i], t[2*i+1]);
}

void upd(int p, int val) {
	upd(1, p, p, val);
}

int find_max(int i, int l, int r) {
	if(lo[i]>r || hi[i] < l)
		return INT_MIN;
	if(l<=lo[i] && hi[i]<=r)
		return t[i];
	return max(find_max(2*i, l, r), find_max(2*i+1, l, r));
}


int find_max(int l, int r) {
	return find_max(1, l, r);
}


int query(int a, int b) { // b is the lca
	int res = INT_MIN;
	for(; head[a] != head[b]; b = parent[head[b]]) {
		if(de[head[a]] > de[head[b]])
			swap(a, b);
		int cur_heavy = find_max(pos[head[b]], pos[b]);
		res = max(res, cur_heavy);
	}
	if(de[a] > de[b])
		swap(a, b);
	int cur_heavy = find_max(pos[a], pos[b]);
	res = max(res, cur_heavy);
	return res;
	/* int s = INT_MIN; */
	/* while(head[a] != head[b]) { */
	/* 	int h = head[a]; */
	/* 	int l = pos[h]; */
	/* 	int r = pos[a]; */
	/* 	s = max(s, find_max(l, r)); */
	/* 	a = parent[h]; */
	/* } */
	/* int h = head[a]; */
	/* int l = pos[h] + de[b] - de[h]; */
	/* int r = l + de[a] - de[h]; */
	/* s=max(s, find_max(l ,r)); */
	/* return s; */
}

void find_lca(int a, int b) {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	fora(i, 1, n+1) cin >> v[i];
	forn(_, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	dfs(1);
	build_hld(1, 1);

	build(1, 0, n-1);

	forn(_, q) {
		int t;
		cin >> t;
		if(t == 1) {
			ll s, x;
			cin >> s >> x;
			int p = pos[s];
			upd(p, x);
			v[s] = x;
		} else {
			int a, b;
			cin >> a >> b;
			/* int lca = find_lca(a, b); */
			/* cout << max(query(a, lca), query(b, lca)) << ' ' << endl; */
			cout << query(a, b) << ' ';
		}
	}
}
