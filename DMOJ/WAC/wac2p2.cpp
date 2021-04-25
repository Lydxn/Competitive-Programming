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

vector<pll> buy;
unordered_map<ll, ll> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, M, Q, p, d, pd = N, pp = 1000000;
	cin >> N >> M >> Q;
	for (int i = 0; i < Q; i++, pp = p, pd = d) {
		cin >> d >> p;
		buy.emplace_back(pp, max(0LL, pd - d - 1));
		if (!mp.count(d)) mp[d] = pp;
		mp[d] = min(mp[d], p);
	}
	buy.emplace_back(pp, pd - 1);

	for (auto m : mp) buy.emplace_back(m.second, 1);
	sort(buy.begin(), buy.end());

	ll ans = 0;
	for (int i = 0; i < int(buy.size()) && M > 0; i++) {
		ans += buy[i].first * min(M, buy[i].second);
		M -= buy[i].second;
	}
	cout << ans << '\n';
	return 0;
}
