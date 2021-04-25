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

int G[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int D, N, C, T;
	cin >> D;
	while (D--) {
		cin >> N >> C >> T;
		for (int i = 0; i < N; i++) cin >> G[i];

		int first = G[0], cur = 0;
		sort(G, G + N);
		for (int i = 0; i < N; i++)
			if (first == G[i]) cur = i;

		int ans1 = 0, ans2 = 0;
		while (cur < N) {
			ans1 = max(ans1, G[cur]);
			int j = cur;
			while (j + 1 < N && G[j + 1] - G[cur] <= C) ++j;
			if (cur == j) break;
			ans2 += T, cur = j;
		}
		cout << ans1 << ' ' << ans2 << '\n';
	}
	return 0;
}
