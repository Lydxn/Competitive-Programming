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

bool dp[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x, s = 0;
	cin >> n; dp[0] = true;
	while (n--) {
		cin >> x, s += x;
		for (int i = s; i >= x; i--)
			dp[i] |= dp[i - x];
	}

	int cnt = 0;
	for (int i = 1; i <= s; i++) cnt += dp[i];

	cout << cnt << '\n';
	for (int i = 1; i <= s; i++)
		if (dp[i]) cout << i << ' ';
	cout << '\n';
	return 0;
}
