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

int tr[2][3200000], idx[3200000], tidx = 1;

void insert(int i, int x) {
	int cur = 0;
	for (int b = 30; b >= 0; b--) {
		bool bit = (x >> b) & 1;
		if (!tr[bit][cur]) tr[bit][cur] = tidx++;
		cur = tr[bit][cur];
	}
	if (idx[cur] == -1) idx[cur] = i;
}

int query(int x) {
	int cur = 0;
	for (int b = 30; b >= 0; b--) {
		bool bit = (x >> b) & 1;
		cur = tr[bit][cur] ? tr[bit][cur] : tr[bit ^ 1][cur];
	}
	return idx[cur];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, x;
	cin >> N >> Q;

	memset(idx, -1, sizeof(idx));
	for (int i = 0; i < N; i++) cin >> a, insert(i, a);

	int xx = 0;
	while (Q--) {
		cin >> x;
		cout << query(xx ^= x) << '\n';
	}
	return 0;
}
