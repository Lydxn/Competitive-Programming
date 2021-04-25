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

bool dp[10001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, num, sum = 0;
	cin >> N;

	dp[0] = true;
	while (N--) {
		cin >> num;
		for (int i = 10000; i >= num; i--)
			dp[i] |= dp[i - num];
		sum += num;
	}

	int ans = INF;
	for (int i = 0; i <= sum; i++)
		if (dp[i])
			ans = min(ans, abs(sum - 2 * i));
	cout << ans << '\n';
	return 0;
}
