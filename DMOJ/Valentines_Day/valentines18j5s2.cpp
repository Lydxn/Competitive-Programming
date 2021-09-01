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

int C[10], D[10], Q[10][10], n[10], cnt[10];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, ans = INF;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> C[i];
	for (int i = 0; i < M; i++) {
		cin >> D[i];
		for (int j = 0; j < N; j++) cin >> Q[i][j];
	}
	for (int i = 0; i < N; i++) cin >> n[i];
	for (int i = 0; i < 1 << M; i++) {
		int s = 0; memset(cnt, 0, N << 2);
		for (int j = 0; j < M; j++) {
			if (i & (1 << j)) {
				s += D[j];
				for (int k = 0; k < N; k++) cnt[k] += Q[j][k];
			}
		}
		for (int j = 0; j < N; j++) {
			if (cnt[j] > n[j]) goto nxt;
			s += (n[j] - cnt[j]) * C[j];
		}
		ans = min(ans, s); nxt:;
	}
	cout << ans << '\n';
	return 0;
}
