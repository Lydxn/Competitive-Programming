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

struct box {
	int L, W, H, P, idx;
	bool operator< (box b) const {
		return H < b.H || (H == b.H && L < b.L) || (H == b.H && L == b.L && W < b.W);
	}
} b[100001];
int N, par[100001], ans[100001], BIT[5001][5001];
ll dp[100001];

void update(int l, int w, int p) {
	for (int i = l; i <= 5000; i += i & -i)
		for (int j = w; j <= 5000; j += j & -j)
			BIT[i][j] = dp[BIT[i][j]] > dp[p] ? BIT[i][j] : p;
}

int query(int l, int w) {
	int res = 0;
	for (int i = l; i; i -= i & -i)
		for (int j = w; j; j -= j & -j)
			res = dp[res] > dp[BIT[i][j]] ? res : BIT[i][j];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> b[i].L >> b[i].W >> b[i].H >> b[i].P;
		if (b[i].L < b[i].W) swap(b[i].L, b[i].W);
		b[i].idx = i;
	}

	sort(b + 1, b + N + 1);
	int mi = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[par[i] = query(b[i].L, b[i].W)] + b[i].P;
		if (dp[i] > dp[mi]) mi = i;
		update(b[i].L, b[i].W, i);
	}

	cout << dp[mi] << '\n';
	int len = 0;
	while (mi) ans[len++] = b[mi].idx, mi = par[mi];

	cout << len << '\n';
	for (int i = 0; i < len; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
