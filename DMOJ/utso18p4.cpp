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

vector<pii> v[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, M; ll ans = 0;
	cin >> N;
	while (N--) {
		cin >> K >> M;
		v[K + M].emplace_back(K, M);
	}

	for (int i = 0; i <= 100000; i++) {
		if (v[i].empty()) continue;
		sort(v[i].begin(), v[i].end());
		ll sk = 0, sm = 0;
		for (auto j : v[i]) sk += j.first;
		for (auto j : v[i]) sk -= j.first, sm += j.second, ans = max(ans, min(sk, sm));
	}
	cout << ans << '\n';
	return 0;
}
