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

int x[5000];
ll dp[5000][5000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n; ll s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i], s += dp[i][i] = x[i];
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
			dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
	cout << (s + dp[0][n - 1]) / 2 << '\n';
	return 0;
}
