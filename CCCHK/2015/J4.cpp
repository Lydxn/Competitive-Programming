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

pair<int, bool> seg[200002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int L, N, s, t;
	cin >> L >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		seg[i << 1] = {s, 1}, seg[i << 1 | 1] = {t, 0};
	}

	seg[N << 1] = {0, 0}, seg[N << 1 | 1] = {L, 1};
	sort(seg, seg + (N << 1) + 2);

	int ans = 0;
	for (int i = 0; i < (N << 1) + 1; i++) {
		if (!seg[i].second && seg[i + 1].second)
			ans = max(ans, seg[i + 1].first - seg[i].first);
	}
	cout << ans << '\n';
	return 0;
}
