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

const int p[21] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
int dp[1 << 21], ans[21];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		int msk = 0;
		for (int j = 0; j < 21; j++)
			if (a % p[j] == 0) msk |= 1 << j, mx = max(mx, j);
		++dp[msk];
	}

	++mx;
	for (int i = 0; i < mx; i++)
		for (int j = 0; j < 1 << mx; j++)
			if (j & (1 << i))
				dp[j] += dp[j ^ (1 << i)];

	for (int i = 0; i < 1 << mx; i++) {
		int b = __builtin_popcount(i);
		ans[b] = max(ans[b], dp[i]);
	}

	for (int i = 1, cur = 0; i <= N; i++) {
		while (i > ans[cur]) ++cur;
		cout << cur << ' ';
	}
	cout << '\n';
	return 0;
}
