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

const int OFS = 1000000;
int cntx[2000001], cnty[2000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, x, y; ll ans = 0; char c;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		++cntx[x + OFS], ++cnty[y + OFS];
		ans += abs(x) + abs(y);
	}
	
	for (int i = 1; i <= 2000000; i++) cntx[i] += cntx[i - 1];
	for (int i = 1; i <= 2000000; i++) cnty[i] += cnty[i - 1];

	int cx = OFS, cy = OFS;
	while (M--) {
		cin >> c;
		if (c == 'S') ++cy, ans += 2 * cnty[cy - 1] - N;
		if (c == 'J') --cy, ans += N - 2 * cnty[cy];
		if (c == 'I') ++cx, ans += 2 * cntx[cx - 1] - N;
		if (c == 'Z') --cx, ans += N - 2 * cntx[cx];
		cout << ans << '\n';
	}
	return 0;
}
