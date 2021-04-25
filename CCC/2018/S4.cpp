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

unordered_map<int, ll> dp;

ll solve(int N) {
	if (N == 1) return 1;
	if (dp[N]) return dp[N];

	ll res = 0; int sq = sqrt(N);
	for (int i = 1; i <= sq; i++)
		res += (N / i - N / (i + 1)) * solve(i);
	for (int i = 2; N / i > sq; i++)
		res += solve(N / i);
	return dp[N] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	cout << solve(N) << '\n';
	return 0;
}
