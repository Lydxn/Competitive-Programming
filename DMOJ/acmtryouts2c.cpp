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

int Xa[1000], Xb[1000], Ya[1000], Yb[1000], Xc[1000], Yc[1000];
bool hit[1000];

ll area(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs((ll) x1 * (y2 - y3) + (ll) x2 * (y3 - y1) + (ll) x3 * (y1 - y2));
}

bool inside(int x, int y, int idx) {
	ll A = area(Xa[idx], Ya[idx], Xb[idx], Yb[idx], Xc[idx], Yc[idx]);
	ll A1 = area(x, y, Xb[idx], Yb[idx], Xc[idx], Yc[idx]);
	ll A2 = area(Xa[idx], Ya[idx], x, y, Xc[idx], Yc[idx]);
	ll A3 = area(Xa[idx], Ya[idx], Xb[idx], Yb[idx], x, y);
	return A == A1 + A2 + A3;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, F, Xs, Ys, Xd, Yd;
	cin >> T;
	while (T--) {
		cin >> N >> F >> Xs >> Ys >> Xd >> Yd;
		for (int i = 0; i < N; i++) cin >> Xa[i] >> Ya[i] >> Xb[i] >> Yb[i] >> Xc[i] >> Yc[i];

		memset(hit, false, sizeof(hit));
		for (int _ = 0; _ < F + 1; _++) {
			for (int i = 0; i < N; i++)
				hit[i] |= inside(Xs, Ys, i);
			Xs += Xd, Ys += Yd;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) cnt += hit[i];
		cout << cnt << '\n';
	}
	return 0;
}
