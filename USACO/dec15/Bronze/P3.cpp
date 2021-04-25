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

bool bad[51];
int d[51][51];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);

	int N, M, D, S, p, m, t;
	cin >> N >> M >> D >> S;
	memset(bad, true, sizeof(bad));
	while (D--) cin >> p >> m >> t, d[p][m] = t;
	while (S--) {
		cin >> p >> t;
		for (int i = 1; i <= M; i++)
			if (d[p][i] >= t || d[p][i] == 0) bad[i] = false;
	}

	int ans = 0;
	for (int i = 1; i <= M; i++) {
		if (!bad[i]) continue;
		int cnt = 0;
		for (int j = 1; j <= N; j++) cnt += d[j][i] != 0;
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}
