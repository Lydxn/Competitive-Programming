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

char g[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, r = 0, y = 0, b = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		bool br = 0, by = 0, bb = 0;
		char c;
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == 'R' || c == 'O' || c == 'P' || c == 'B') br = true;
			else r += br, br = false;
			if (c == 'Y' || c == 'O' || c == 'G' || c == 'B') by = true;
			else y += by, by = false;
			if (c == 'U' || c == 'G' || c == 'P' || c == 'B') bb = true;
			else b += bb, bb = false;
		}
		r += br, y += by, b += bb;
	}
	cout << r << ' ' << y << ' ' << b << '\n';
	return 0;
}
