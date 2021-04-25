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

int D[200000], b[200000], cnt[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, R, B, Q;
	cin >> N >> K >> R;
	for (int i = 0; i < N; i++) cin >> D[i];
	for (int i = 0; i < R; i++) cin >> B >> Q, b[B] = Q;
	int ans = INF;
	for (int l = 0, r = 0; r < N; r++) {
		if (++cnt[D[r]] == b[D[r]]) --R;
		while (l < N && cnt[D[l]] > b[D[l]]) --cnt[D[l++]];
		if (R == 0) ans = min(ans, r - l + 1);
	}
	if (ans == INF) cout << "impossible\n";
	else cout << ans << '\n';
	return 0;
}
