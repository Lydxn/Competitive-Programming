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

int a[1000], dp[1000][1000];

int solve(int l, int r) {
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	return dp[l][r] = max(a[l] + (a[l + 1] >= a[r] ? solve(l + 2, r) : solve(l + 1, r - 1)),
                          a[r] + (a[l] >= a[r - 1] ? solve(l + 1, r - 1) : solve(l, r - 2)));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	for (int T = 1; cin >> n; T++) {
		if (n == 0) break;
		memset(dp, -1, 4000 * n);
		int s = 0;
		for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
		cout << "In game " << T << ", the greedy strategy might lose by as many as " << 2 * solve(0, n - 1) - s << " points.\n";
	}
	return 0;
}
