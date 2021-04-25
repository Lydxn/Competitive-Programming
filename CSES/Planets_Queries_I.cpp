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

int up[200001][31];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, x, k;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> up[i][0];
	for (int i = 1; i <= 30; i++)
		for (int j = 1; j <= n; j++)
			up[j][i] = up[up[j][i - 1]][i - 1];
	while (q--) {
		cin >> x >> k;
		for (int i = 0; i <= 30; i++)
			if (k & (1 << i)) x = up[x][i];
		cout << x << '\n';
	}
	return 0;
}
