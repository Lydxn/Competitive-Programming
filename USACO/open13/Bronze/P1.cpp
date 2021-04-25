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
	int x, y;
} f[4] = {{0, 1}, {1, 1}, {0, 0}, {1, 0}}, dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("ballet.in", "r", stdin);
	freopen("ballet.out", "w", stdout);

	int N, minx = INF, maxx = 0, miny = INF, maxy = 0, d = 0; string S;
	cin >> N;
	while (N--) {
		cin >> S;

		int idx = S[0] == 'F' ? S[1] == 'L' ? 0 : 1 : S[1] == 'L' ? 2 : 3;
		if (S[2] == 'P') {
			for (int i = 0; i < 4; i++)
				f[i] = {f[idx].x + f[i].y - f[idx].y, f[idx].y + f[idx].x - f[i].x};
			d = (d + 1) % 4;
		} else {
			int didx = ((S[2] == 'F' ? 0 : S[2] == 'R' ? 1 : S[2] == 'B' ? 2 : 3) + d) % 4;
			f[idx].x += dir[didx].x, f[idx].y += dir[didx].y;
			for (int i = 0; i < 4; i++)
				if (i != idx && f[idx].x == f[i].x && f[idx].y == f[i].y)
					{ cout << "-1\n"; return 0; }
		}

		for (int i = 0; i < 4; i++) {
			minx = min(minx, f[i].x), maxx = max(maxx, f[i].x);
			miny = min(miny, f[i].y), maxy = max(maxy, f[i].y);
		}
	}
	cout << (maxx - minx + 1) * (maxy - miny + 1) << '\n';
	return 0;
}
