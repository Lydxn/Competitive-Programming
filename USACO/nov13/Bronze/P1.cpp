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

int N, C[2][3];

int good(int x, int y) {
	return abs(x - y) <= 2 || abs(x - y) >= N - 2;
}

int f(int x, int y, int z) {
	for (int i = 0; i < 2; i++)
		if (good(C[i][0], x) && good(C[i][1], y) && good(C[i][2], z))
			return true;
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	int ans = 0;
	cin >> N;
	for (int i = 0; i < 2; i++) cin >> C[i][0] >> C[i][1] >> C[i][2];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				ans += f(i, j, k);
	cout << ans << '\n';
	return 0;
}
