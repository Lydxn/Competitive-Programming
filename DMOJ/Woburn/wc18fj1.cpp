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

unordered_map<int, int> cnt;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, W, m0 = 0, m1 = 0;
	cin >> N;
	while (N--) cin >> W, ++cnt[W];
	for (auto c : cnt) {
		if (c.second > m1) m0 = m1, m1 = c.second;
		else if (c.second > m0) m0 = c.second;
	}
	cout << m0 + m1 << '\n';
	return 0;
}
