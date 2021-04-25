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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C, N, W, H;
	cin >> C;
	while (C--) {
		cin >> N >> W >> H;
		int ans = INF;
		for (int i = 1; i <= N; i++) {
			if (N % i == 0)
				ans = min(ans, (W * i + N / i * H) << 1);

			int w = W * i;
			if (w % H == 0) {
				int c = w / H;
				for (int j = 1; j * i < N; j++) {
					if ((N - j * i) % c == 0) {
						int d = (N - j * i) / c;
						ans = min(ans, (w + H * j + W * d) << 1);
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
