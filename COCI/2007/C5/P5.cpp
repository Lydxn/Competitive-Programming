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

struct pt {
	int X, Y, F, i;
	bool operator< (const pt &p) const { return X < p.X || (X == p.X && Y < p.Y); }
} p[300000];
int N, mx[300000], my[300000], mxi[300000], myi[300000], prv[300000], ans[300000], aidx;

int find(int x) {
	for (int i = 0; i < N; i++)
		if (p[i].i == x) return i;
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> p[i].X >> p[i].Y >> p[i].F, p[i].i = i;

	sort(p, p + N);
	memset(prv, -1, sizeof(prv)); memset(mx, -INF, sizeof(mx)); memset(my, -INF, sizeof(my));
	
	int idx = find(0);
	mx[p[idx].X] = my[p[idx].Y] = p[idx].F, mxi[p[idx].X] = myi[p[idx].Y] = idx;
	
	for (int i = idx + 1; i < N; i++) {
		int dp = 0;
		if (mx[p[i].X] >= K && dp < mx[p[i].X] - K + p[i].F)
			dp = mx[p[i].X] - K + p[i].F, prv[i] = mxi[p[i].X];
		if (my[p[i].Y] >= K && dp < my[p[i].Y] - K + p[i].F)
			dp = my[p[i].Y] - K + p[i].F, prv[i] = myi[p[i].Y];
		if (mx[p[i].X] < dp)
			mx[p[i].X] = dp, mxi[p[i].X] = i;
		if (my[p[i].Y] < dp)
			my[p[i].Y] = dp, myi[p[i].Y] = i;
		if (p[i].i == N - 1) {
			cout << dp << '\n';
			for (idx = find(N - 1); idx != -1; idx = prv[idx]) ans[aidx++] = idx;
			cout << aidx << '\n';
			for (int j = aidx - 1; j >= 0; j--) cout << p[ans[j]].X << ' ' << p[ans[j]].Y << '\n';
		}
	}
	return 0;
}
