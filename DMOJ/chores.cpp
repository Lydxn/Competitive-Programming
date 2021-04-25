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

pii a[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll ans = 0, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + N, greater<pii>());
	for (int i = 0; i < N; i++) {
		ans = (ans - sum * (sum + 1) / 2 % MOD * a[i].first % MOD + MOD) % MOD;
		sum = (sum + a[i].second) % MOD;
		ans = (ans + sum * (sum + 1) / 2 % MOD * a[i].first) % MOD;
	}
	cout << ans << '\n';
	return 0;
}
