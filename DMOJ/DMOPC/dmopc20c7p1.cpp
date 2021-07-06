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

set<pii, greater<pii>> ss;
map<int, int> cnt;
map<int, vector<int>> mp;
vector<pii> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, m, a = 0;
	cin >> N;
	for (int i = 1; i <= 2 * N; i++) cin >> m, ++cnt[m], mp[m].push_back(i);
	for (auto i : cnt) ss.emplace(i.second, i.first);
	while (ss.size() > 1) {
		auto it = ss.begin(), it2 = next(it);
		ans.emplace_back(mp[it->second].back(), mp[it2->second].back());
		mp[it->second].pop_back(), mp[it2->second].pop_back(), ++a;
		int v = it->first, w = it->second; ss.erase(it);
		if (v > 1) ss.emplace(v - 1, w);
		int v2 = it2->first, w2 = it2->second; ss.erase(it2);
		if (v2 > 1) ss.emplace(v2 - 1, w2);
	}

	int l = ss.begin()->second;
	while (!mp[l].empty()) {
		int v1 = mp[l].back(); mp[l].pop_back();
		int v2 = mp[l].back(); mp[l].pop_back();
		ans.emplace_back(v1, v2);
	}
	cout << a << '\n';
	for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
	return 0;
}
