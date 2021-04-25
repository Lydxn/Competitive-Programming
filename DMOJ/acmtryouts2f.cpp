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

struct qu {
	int type; ll x, y, idk;
	bool operator< (qu &q) const {
		return x < q.x || (x == q.x && type < q.type);
	}
} q[400000];
int BIT[1000001];

void update(int i, int v) {
	for (; i <= 1000000; i += i & -i) BIT[i] += v;
}

int query(int i) {
	int res = 0;
	for (; i; i -= i & -i) res += BIT[i];
	return res;
}

int query(int l, int r) {
	return query(r) - query(l - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; ll X, Y, N, L; char D; string S;
	cin >> T;
	while (T--) {
		cin >> S;
		int qidx = 0;
		for (int _ = 0; _ < 2; _++) {
			cin >> X >> Y >> N;
			for (int i = 0; i < N; i++) {
				cin >> D >> L;
				if (D == 'L') q[qidx++] = {0, X, Y, -1}, q[qidx++] = {0, X -= L, Y, 1};
				else if (D == 'R') q[qidx++] = {0, X, Y, 1}, q[qidx++] = {0, X += L, Y, -1};
				else if (D == 'U') q[qidx++] = {1, X, Y, Y + L}, Y += L;
				else if (D == 'D') q[qidx++] = {1, X, Y - L, Y}, Y -= L;
			}
		}

		sort(q, q + qidx);
		ll ans = 0;
		memset(BIT, 0, sizeof(BIT));
		for (int i = 0; i < qidx; i++) {
			if (q[i].type == 0) update(q[i].y, q[i].idk);
			else ans += query(q[i].y + 1, q[i].idk - 1);
		}
		cout << ans << '\n';
	}
	return 0;
}
