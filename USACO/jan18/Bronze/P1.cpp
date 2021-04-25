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

struct rect {
	int x1, y1, x2, y2;
} a, b;

bool f(int x, int y) {
	return b.x1 <= x && x <= b.x2 && b.y1 <= y && y <= b.y2;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	int c = f(a.x1, a.y1) + f(a.x2, a.y2) + f(a.x1, a.y2) + f(a.x2, a.y1);
	if (c == 4) cout << "0\n";
	else if (c <= 1) cout << (a.x2 - a.x1) * (a.y2 - a.y1) << '\n';
	else cout << (a.x2 - a.x1) * (a.y2 - a.y1) - (min(a.x2, b.x2) - max(a.x1, b.x1)) * (min(a.y2, b.y2) - max(a.y1, b.y1)) << '\n';
	return 0;
}
