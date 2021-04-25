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

int x[100000], y[100000];

int f(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);

	int N, ans = 0, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	for (int i = 1; i < N; i++) ans += f(i - 1, i);
	for (int i = 1; i < N - 1; i++) {
		int a = f(i - 1, i) + f(i, i + 1), b = f(i - 1, i + 1);
		mx = max(mx, a - b);
	}
	cout << ans - mx << '\n';
	return 0;
}
