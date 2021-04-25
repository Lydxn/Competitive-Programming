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

pii p[2001];
int dp[2001];
set<pii> ss;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, I, D, S;
	cin >> N >> I >> D >> S;
	for (int i = 1; i <= N; i++) cin >> p[i].first >> p[i].second, ss.insert(p[i]);
	int sz = N;
	for (int i = 1; i <= N; i++)
		if (p[i].second - S >= 0 && !ss.count({p[i].first, p[i].second - S}))
			p[++sz] = {p[i].first, p[i].second - S};
	sort(p + 1, p + sz + 1);
	for (int i = 1; i <= sz; i++) {
		int mx = -INF;
		for (int j = 0; j < i; j++) {
			if (p[i].first == p[j].first) continue;
			if ((p[i].second > p[j].second && 1LL * (p[i].first - p[j].first) * I >= (p[i].second - p[j].second))
			 || (p[i].second < p[j].second && 1LL * (p[i].first - p[j].first) * D >= (p[j].second - p[i].second))
			 || p[i].second == p[j].second) mx = max(mx, dp[j]);
		}
		dp[i] = mx + ss.count(p[i]) + (S > 0 && ss.count({p[i].first, p[i].second + S}));
	}

	int ans = 0;
	for (int i = 1; i <= sz; i++) ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}