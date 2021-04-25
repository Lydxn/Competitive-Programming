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

int dp0[31], dp1[31];

void solve() {
	int N;
	cin >> N;
	cout << dp1[N] % 1000000 << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	dp0[1] = 1, dp1[0] = 1;
	for (int i = 2; i <= 30; i++)
		dp0[i] = dp0[i - 2] + dp1[i - 1], dp1[i] = dp1[i - 2] + 2 * dp0[i - 1];

	for (int _ = 0; _ < 5; _++) solve();
	return 0;
}
