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

pair<int, double> d[101];
double dp[200001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C, D, K, c; double tot = 0, ans = INFL;
	cin >> C >> D >> K;
	for (int i = 1; i <= D; i++) cin >> d[i].first >> d[i].second;
	for (int i = 1; i <= 200000; i++) dp[i] = -INFL;
	for (int i = 1; i <= K; i++) {
		cin >> c; tot += d[c].second;
		for (int j = 200000; j >= d[c].first; j--)
			dp[j] = max(dp[j], dp[j - d[c].first] + d[c].second);
	}

	sort(d + 1, d + D + 1, greater<pair<int, double>>());
	for (int i = C; i <= 200000; i++) {
		if (dp[i] == -INFL) continue;
		double cur = 0; int left = i - C;
		for (int j = 1; j <= D; j++) {
			cur += left / d[j].first * d[j].second;
			left %= d[j].first;
		}
		ans = min(ans, tot - dp[i] + cur);
	}

	if (ans == INFL) cout << "too poor\n";
	else cout << fixed << setprecision(2) << ans << '\n';
	return 0;
}
