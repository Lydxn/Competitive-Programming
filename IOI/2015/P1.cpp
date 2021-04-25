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

ll l[10000001], r[10000001];

ll delivery(int N, int K, int L, int positions[]) {
	for (int i = 0; i < N; i++) l[i] = min(positions[i] << 1, L) + (i - K >= 0 ? l[i - K] : 0);
	for (int i = N - 1; i >= 0; i--) r[i] = min((L - positions[i]) << 1, L) + (i + K < N ? r[i + K] : 0);

	ll ans = r[0];
	for (int i = 0; i < N; i++) ans = min(ans, l[i] + r[i + 1]);
	return ans;
}