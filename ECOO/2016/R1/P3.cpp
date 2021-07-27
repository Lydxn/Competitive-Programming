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

int N, ind[1001], bit[1002];

void update(int i, int v) {
	for (; i <= N + 1; i += i & -i) bit[i] += v;
}

int query(int i) {
	int s = 0;
	for (; i; i -= i & -i) s += bit[i];
	return s;
}

void solve() {
	cin >> N;
	memset(bit, 0, (N + 2) << 2);
	for (int i = 1, a; i <= N; i++) {
		cin >> a, ind[a] = i;
		update(i, i - 1), update(i + 1, -(i - 1));
	}
	int st = N - 1, ans = 0;
	while (st && ind[st] < ind[st + 1]) --st;
	for (int i = st; i; i--) {
		ans += query(ind[i]);
		update(1, 1), update(ind[i], -1);
	}
	cout << ans << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 10; _++) solve();
	return 0;
}
