#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int t[6000001][2], tidx;

void insert(int x) {
	int cur = 0;
	for (int i = 30; i >= 0; i--) {
		int b = (x >> i) & 1;
		if (!t[cur][b]) t[cur][b] = ++tidx;
		cur = t[cur][b];
	}
}

int query(int x) {
	int res = 0, cur = 0;
	for (int i = 30; i >= 0; i--) {
		int b = (x >> i) & 1;
		if (t[cur][!b]) cur = t[cur][!b], res |= 1 << i;
		else cur = t[cur][b];
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x, s = 0, ans = 0;
	cin >> n;
	insert(0);
	while (n--) {
		cin >> x, s ^= x;
		insert(s);
		ans = max(ans, query(s));
	}
	cout << ans << '\n';
	return 0;
}
