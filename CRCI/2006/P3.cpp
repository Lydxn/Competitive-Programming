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

int d0[500001], d1[500001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, H;
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (i % 2 == 0) ++d0[x];
		else ++d1[H - x + 1];
	}
	for (int i = H - 1; i; i--) d0[i] += d0[i + 1];
	for (int i = 2; i <= H; i++) d1[i] += d1[i - 1];
	int mn = INF, cnt = 0;
	for (int i = 1; i <= H; i++) mn = min(mn, d0[i] + d1[i]);
	for (int i = 1; i <= H; i++) cnt += mn == d0[i] + d1[i];
	cout << mn << ' ' << cnt << '\n';
	return 0;
}
