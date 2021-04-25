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

int e[1001];

void solve() {
	int N, M, D, A;
	cin >> N >> M >> D;

	memset(e, false, sizeof(e));
	for (int i = 0; i < M; i++) cin >> A, ++e[A];

	int ans = 0;
	for (int i = 1, n = N; i <= D; i++) {
		if (n == 0) n = N, ++ans;
		n += e[i] - 1, N += e[i];
	}
	cout << ans << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 10; _++) solve();
	return 0;
}
