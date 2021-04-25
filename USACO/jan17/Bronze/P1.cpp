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

unordered_map<string, int> mp;
pair<int, string> cnt[7];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

	int N, x; string s;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s >> x, mp[s] += x;

	int idx = 0;
	for (auto m : mp) cnt[idx++] = {m.second, m.first};
	sort(cnt, cnt + 7);
	int ans = 0;
	while (ans < 7 && cnt[ans].first == cnt[0].first) ++ans;
	cout << (ans == 7 || cnt[ans].first == cnt[ans + 1].first ? "Tie" : cnt[ans].second) << '\n';
	return 0;
}
