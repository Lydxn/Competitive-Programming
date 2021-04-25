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

int t[101];
double prob[101], dp[8641];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, T, A, a, ans = 0;
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) cin >> t[i];
	while (M--) {
		cin >> A;
		if (A == 0) ++ans;
		else {
			double p = 1.0 / A;
			for (int i = 0; i < A; i++) cin >> a, prob[a] += p;
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = T; j >= t[i]; j--)
			dp[j] = max(dp[j], dp[j - t[i]] + prob[i]);
	cout << fixed << setprecision(2) << dp[T] + ans << '\n';
	return 0;
}
