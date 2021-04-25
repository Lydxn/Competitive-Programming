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

int cnt[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n; memset(cnt, 0, sizeof(cnt));
		while (n--) cin >> a, ++cnt[a];
		int a1 = 0, a2 = 0;
		while (a1 <= 100 && cnt[a1] >= 1) ++a1;
		while (a2 <= 100 && cnt[a2] >= 2) ++a2;
		cout << a1 + a2 << '\n';
	}
	return 0;
}
