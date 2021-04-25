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

int cups[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, T, L, a, b, c;
	cin >> N >> T;
	while (T--) cin >> a >> b >> c, cups[a] += c, cups[b + 1] -= c;
	for (int i = 1; i <= N; i++) cups[i] += cups[i - 1];

	cin >> L;
	int ans = 0, sum = 0;
	for (int l = 1, r = 0; l <= N; l++) {
		while (r <= N && sum <= L) sum += cups[++r];
		sum -= cups[l], ans = max(ans, r - l);
	}
	cout << ans << '\n';
	return 0;
}
