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

struct query {
	int v, l, r; bool b;
	bool operator< (const query &q) { return v < q.v || (v == q.v && b > q.b); }
} x[10000], y[10000];
int cnt[20001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x1, y1, x2, y2, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 10000, y1 += 10000, x2 += 10000, y2 += 10000;
		x[i << 1] = {y1, x1, x2, true}, x[i << 1 | 1] = {y2, x1, x2, false};
		y[i << 1] = {x1, y1, y2, true}, y[i << 1 | 1] = {x2, y1, y2, false};
	}

	N <<= 1, sort(x, x + N), sort(y, y + N);
	for (int i = 0; i < N; i++)
		if (x[i].b) for (int j = x[i].l; j < x[i].r; j++) ans += !cnt[j]++;
		else        for (int j = x[i].l; j < x[i].r; j++) ans += !--cnt[j];
	for (int i = 0; i < N; i++)
		if (y[i].b) for (int j = y[i].l; j < y[i].r; j++) ans += !cnt[j]++;
		else        for (int j = y[i].l; j < y[i].r; j++) ans += !--cnt[j];
	cout << ans << '\n';
	return 0;
}
