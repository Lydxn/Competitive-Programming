#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int mud[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, J, p, t;
	cin >> N >> M >> J;

	memset(mud, INF, sizeof(mud));
	while (M--) cin >> p >> t, mud[p] = t;

	int idx = 0, time = 0;
	while (idx + J <= N) {
		int mn = INF, mi = -1;
		for (int i = idx + J; i > idx; i--)
			if (mud[i] < mn)
				mn = mud[i], mi = i;

		if (mi == -1) {
			cout << "-1\n";
			return 0;
		}

		idx = mi, time = max(time, mn);
	}

	cout << time << '\n';
	return 0;
}
