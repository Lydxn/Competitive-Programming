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

int adj[20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b; --a, --b;
		adj[a] |= 1 << b, adj[b] |= 1 << a;
	}

	int ans = 0;
	for (int i = 0; i < 1 << N; i++) {
		bool good = true;
		for (int j = 0; j < N; j++)
			good &= (i & (1 << j)) == 0 || (i & adj[j]) == 0;
		ans += good;
	}
	cout << ans << '\n';
	return 0;
}
