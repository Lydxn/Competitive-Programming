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
	int a, b, idx;
	bool operator< (qu &q) const { return a < q.a || (a == q.a && b < q.b); }
} R[300000];
int BIT[100001], ans[300000];

void update(int x) {
	for (; x <= 100000; x += x & -x) ++BIT[x];
}

int query(int x) {
	int res = 0;
	for (; x; x -= x & -x) res += BIT[x];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> R[i].a >> R[i].b, R[i].idx = i;

	sort(R, R + N);
	for (int i = 0, p = 0; i < N; i++) {
		ans[R[i].idx] = query(R[i].b);
		if (i && R[i].a == R[i - 1].a && R[i].b == R[i - 1].b)
			ans[R[i].idx] -= i - p;
		else
			p = i;
		update(R[i].b);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << '\n';
	return 0;
}
