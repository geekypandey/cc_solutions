#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	indexed_set s;
	for(int i = 1; i <=n; i++) s.insert(i);

	int start = 0;
	for(int i = 0; i < n; i++) {
		int next = (start+k)%s.size();
		int x = *s.find_by_order(next);
		cout << x << ' ';
		s.erase(x);
		start = next;
	}


	return 0;
}
