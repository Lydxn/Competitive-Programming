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

#define wtf(a, b) ((ll) (a) << 30LL | (b))

int a[200000][20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, ans = 0;
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) cin >> a[i][j];
	unordered_set<ll> ss;
	for (int i = 0; i < N - 1; i++) {
		ss.clear();
		for (int j = M - 1; j >= 0; j--) {
			ans += ss.count(wtf(a[j][i] + K, a[j][i + 1] + K));
			if (a[j][i] >= K && a[j][i + 1] >= K) ans += ss.count(wtf(a[j][i] - K, a[j][i + 1] - K));
			ss.insert(wtf(a[j][i], a[j][i + 1]));
		}
	}
	cout << ans << '\n';
	return 0;
}
