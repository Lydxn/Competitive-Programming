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

int c[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("baseball.in", "r", stdin);
	freopen("baseball.out", "w", stdout);

	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> c[i];
	sort(c, c + N);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int l = lower_bound(c + j + 1, c + N, 2 * c[j] - c[i]) - c;
			int r = upper_bound(c + j + 1, c + N, 3 * c[j] - 2 * c[i]) - c - 1;
			ans += max(0, r - l + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}
