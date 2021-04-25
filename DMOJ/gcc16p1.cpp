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

pii p[400001];
int pidx = 1;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, A, C, a, b, c, d;
	cin >> N >> A >> C;
	for (int i = 0; i < A; i++)
		cin >> a >> b, p[pidx++] = {a, 0}, p[pidx++] = {b + 1, 1};
	for (int i = 0; i < C; i++)
		cin >> c >> d, p[pidx++] = {c, 2}, p[pidx++] = {d + 1, 3};

	sort(p, p + (A + C) * 2 + 1);
	int ans = 0, cnt0 = 0, cnt1 = 0;
	for (int i = 1; i < pidx; i++) {
		if (!cnt1 && cnt0) ans += p[i].first - p[i - 1].first;
		if (p[i].second == 0) ++cnt0;
		else if (p[i].second == 1) --cnt0;
		else if (p[i].second == 2) ++cnt1;
		else --cnt1;
	}
	cout << ans << '\n';
	return 0;
}
