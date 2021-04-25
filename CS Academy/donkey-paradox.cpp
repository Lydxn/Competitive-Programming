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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, r1, c1, r2, c2;
	cin >> N >> M >> r1 >> c1 >> r2 >> c2;

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			ans += abs(r1 - i) + abs(c1 - j) == abs(r2 - i) + abs(c2 - j);
	cout << ans << '\n';
	return 0;
}
