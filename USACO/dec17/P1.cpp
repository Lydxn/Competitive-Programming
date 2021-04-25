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
} r[3];
int d[2001][2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	for (int i = 0; i < 3; i++) {
		cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
		r[i].x1 += 1000, r[i].y1 += 1000, r[i].x2 += 1000, r[i].y2 += 1000;
	}
	
	for (int i = 0; i < 2; i++) {
		for (int j = r[i].x1; j < r[i].x2; j++)
			for (int k = r[i].y1; k < r[i].y2; k++)
				d[j][k] = true;
	}
	
	for (int j = r[2].x1; j < r[2].x2; j++)
		for (int k = r[2].y1; k < r[2].y2; k++)
			d[j][k] = false;

	int ans = 0;
	for (int i = 0; i <= 2000; i++)
		for (int j = 0; j <= 2000; j++)
			ans += d[i][j];
	cout << ans << '\n';
	return 0;
}
