// if only i wasn't bad i wouldn't have flunked the contest :(

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

ll a[1500];
unordered_map<ll, ll> cnt;
unordered_map<ll, vector<pll>> cnt2;
vector<pll> v;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i], ++cnt[a[i]];
	for (auto i : cnt) v.push_back(i);
	
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		if (v[i].second > 1) cnt2[v[i].first * v[i].first].push_back({-1, v[i].second});
		for (int j = i + 1; j < vs; j++) {
			cnt2[v[i].first * v[j].first].push_back({v[i].second, v[j].second});
		}
	}

	for (auto i : cnt2) {
		ll s = 0;
		for (auto j : i.second) {
			if (j.first == -1) s += j.second * (j.second - 1) / 2;
			else s += j.first * j.second;
		}

		ll m, t = 0;
		for (auto j : i.second) {
			if (j.first == -1) {
				m = j.second * (j.second - 1) / 2;
				t += (s - m) * m;
				//cout << j.second << '\n';
				if (j.second > 3) t += (j.second - 2) * (j.second - 3) / 2 * j.second * (j.second - 1) / 2;
			} else {
				m = j.first * j.second;
				t += (s - m) * m;
				t += (j.first - 1) * (j.second - 1) * j.first * j.second;
			}
		}
		//cout << t << ' ' << i.first << '\n';
		ans += t;
	}
	cout << ans * 4 << '\n';
	return 0;
}
