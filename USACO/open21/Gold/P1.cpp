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

int N, bit[200001], ind[200001];

void update(int i, int v) {
	for (; i <= N; i += i & -i) bit[i] += v;
}

int query(int i) {
	int res = 0;
	for (; i; i -= i & -i) res += bit[i];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int b; ll ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> b;
		ans += query(i) - query(ind[b]);
		if (ind[b]) update(ind[b], -1);
		update(i, 1), ind[b] = i;
	}
	cout << ans << '\n';
	return 0;
}
