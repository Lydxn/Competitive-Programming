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

int s[3001][3001], q[3001][3001];

int rectangle(int R, int C, int H, int W, int Q[3001][3001]) {
	int l = 1, r = R * C;
	while (l <= r) {
		int mid = (l + r) >> 1;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				s[i][j] = Q[i - 1][j - 1] < mid ? 1 : -1;
				s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			}
		}
		for (int i = H; i <= R; i++)
			for (int j = W; j <= C; j++)
				if (s[i][j] - s[i - H][j] - s[i][j - W] + s[i - H][j - W] >= 0)
					{ r = mid - 1; goto nxt; }
		l = mid + 1; nxt:;
	}
	return r;
}