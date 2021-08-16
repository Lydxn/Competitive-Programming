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

int a[19], m[19], dp[1 << 19];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> m[i];
	for (int i = 1; i < 1 << N; i++) dp[i] = INT_MIN;
	dp[0] = 0;
	for (int i = 0; i < 1 << N; i++) {
		int sz = __builtin_popcount(i);
		for (int j = 0; j < N; j++)
			if (!(i & (1 << j)))
				dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + a[j] * m[(sz + j) % N]);
	}
	cout << dp[(1 << N) - 1] << '\n';
	return 0;
}
