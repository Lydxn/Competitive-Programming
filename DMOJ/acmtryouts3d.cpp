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

int T[100], F[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, D, M, H, L;
	cin >> N;
	while (N--) {
		cin >> D >> M >> H >> L;
		for (int i = 0; i < M; i++) cin >> T[i] >> F[i];

		ll ans = INFL;
		for (int i = 0; i <= M; i++) {
			ll fright = 0, hold = 0;
			for (int j = 0; j < M; j++) {
				if (fright >= L) break;
				if (fright >= H) hold += T[j] - (j ? T[j - 1] : 0);
				if (i != j) fright = max(0LL, fright + F[j]);
			}

			if (fright >= H && fright < L) hold += D - T[M - 1];
			ans = min(ans, hold);
		}
		cout << (M ? ans : 0) << '\n';
	}
	return 0;
}
