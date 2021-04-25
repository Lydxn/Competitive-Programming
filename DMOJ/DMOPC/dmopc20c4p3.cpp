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
	int x, y; bool t;
	bool operator< (const qu &q) { return x < q.x || (x == q.x && t < q.t); }
} q[400000];
int qidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, X, Y;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> X >> Y, q[qidx++] = {X, Y, 1};
	for (int i = 0; i < M; i++) cin >> X >> Y, q[qidx++] = {X, Y, 0};

	sort(q, q + qidx);
	ordered_set<pii> os; ll ans = 0;
	for (int i = 0; i < qidx; i++) {
		if (q[i].t == 0) os.insert({q[i].y, i});
		else ans += os.size() - os.order_of_key({q[i].y, -1});
	}
	cout << ans << '\n';
	return 0;
}
