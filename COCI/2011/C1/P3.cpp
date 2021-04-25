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

int cnt[2][20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x;
	cin >> N;
	while (N--) {
		cin >> x;
		for (int i = 0; i < 20; i++) ++cnt[(x >> i) & 1][i];
	}

	ll ans = 0;
	for (int i = 0; i < 20; i++) ans += 1LL * (1 << i) * cnt[0][i] * cnt[1][i];
	cout << ans << '\n';
	return 0;
}
