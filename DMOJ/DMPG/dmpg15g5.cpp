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

priority_queue<int> V[2001];
ll dp[2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, R, E, C1, V1, CA, CB, CM, VA, VB, VM; ll free = 0;
	cin >> N >> R;
	while (N--) {
		cin >> E >> C1 >> V1 >> CA >> CB >> CM >> VA >> VB >> VM;
		while (E--) {
			if (C1 == 0) free += V1;
			else if (C1 <= R) V[C1].push(V1);
			C1 = (1LL * C1 * CA + CB) % CM, V1 = (1LL * V1 * VA + VB) % VM;
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int c = R / i; !V[i].empty() && c; c--) {
			int v = V[i].top(); V[i].pop();
			for (int j = R; j >= i; j--)
				dp[j] = max(dp[j], dp[j - i] + v);
		}
	}
	cout << dp[R] + free << '\n';
	return 0;
}