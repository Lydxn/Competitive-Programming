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

ll diff[1002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, L, N, M, C, R, D, H;
	cin >> T;
	while (T--) {
		memset(diff, 0, sizeof(diff));
		cin >> L >> N;
		while (N--) {
			cin >> C >> R >> D;
			diff[max(1, C - R)] += D, diff[min(L + 1, C + R + 1)] -= D;
		}

		for (int i = 1; i <= L; i++) diff[i] += diff[i - 1];
		for (int i = 1; i <= L; i++) diff[i] += diff[i - 1];

		cin >> M;
		while (M--) {
			cin >> H;
			int ans = lower_bound(diff + 1, diff + L + 1, H) - diff;
			if (ans > L) cout << "Bloon leakage\n";
			else cout << ans << '\n';
		}
	}
	return 0;
}
