#pragma GCC optimize "Ofast"
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

int c[30001], v[30001], dp[51];
int z[51][1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int B, N, D, a, b, x, y;
	cin >> B >> N >> D;
	for (int i = 1; i <= N; i++) cin >> c[i] >> v[i];
	while (D--) {
		cin >> a >> b >> x >> y; c[a] = b;
		memset(z, 0, sizeof(z));
		for (int i = x; i <= y; i++)
			if (c[i] <= B) ++z[c[i]][v[i]];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= B; i++)
			for (int j = B / i, mx = 1000; j && mx; mx--)
				while (j && z[i][mx]--) {
					j--;
					for (int k = B; k >= i; k--)
						dp[k] = max(dp[k], dp[k - i] + mx);
				}
		cout << dp[B] << '\n';
	}
	return 0;
}