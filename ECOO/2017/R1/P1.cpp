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

void solve() {
	int cost, st, Z[4]; double Y[4];
	cin >> cost >> Y[0] >> Y[1] >> Y[2] >> Y[3] >> st;

	int h = 0, xtra = 0;
	for (int i = 0; i < 4; i++) {
		Z[i] = Y[i] * st, xtra += Z[i];
		if (Z[i] > Z[h]) h = i;
	}
	Z[h] += st - xtra;
	cout << (Z[0] * 12 + Z[1] * 10 + Z[2] * 7 + Z[3] * 5 < 2 * cost ? "YES" : "NO") << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 10; _++) solve();
	return 0;
}
