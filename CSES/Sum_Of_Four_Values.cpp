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

int a[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x; map<int, pii> cnt;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int k = x - a[i] - a[j];
			if (cnt.count(k)) {
				cout << i + 1 << ' ' << j + 1 << ' ' << cnt[k].first + 1 << ' ' << cnt[k].second + 1 << '\n';
				return 0;
			}
		}
		for (int j = 0; j < i; j++)
			cnt[a[i] + a[j]] = {i, j};
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
