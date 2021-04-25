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

int s1[1000001], s2[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("cowrace.in", "r", stdin);
	freopen("cowrace.out", "w", stdout);

	int N, M, s, t, tot = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		while (t--) s1[tot++] = s;
	}
	tot = 0;
	for (int i = 0; i < M; i++) {
		cin >> s >> t;
		while (t--) s2[tot++] = s;
	}
	int ans = 0;
	for (int i = 0, cur1 = 0, cur2 = 0, last = -1; i < tot; i++) {
		cur1 += s1[i], cur2 += s2[i];
		if (cur2 > cur1) ans += last == 1, last = 2;
		if (cur1 > cur2) ans += last == 2, last = 1;
	}
	cout << ans << '\n';
	return 0;
}
