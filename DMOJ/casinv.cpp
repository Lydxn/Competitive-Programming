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

int c[1000000];
ll psa[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, r; ll ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> c[i];
	sort(c + 1, c + N + 1);

	for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + c[i];

	int mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> r;
		if (r > c[N]) {
			cout << "-1\n";
			return 0;
		}

		int b = upper_bound(c + 1, c + N + 1, r) - c;
		ans += psa[b - 1] + (ll) (N - b + 1) * r;
		mx = max(mx, b);
	}

	if (mx <= N) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}
