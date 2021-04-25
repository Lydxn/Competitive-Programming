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

int dx[1000001], dy[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, x1, y1, x2, y2, x3, y3, c; char op, _;
	cin >> N;
	while (N--) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		++dx[min(x1, min(x2, x3)) + 1], --dx[max(x1, max(x2, x3))];
		++dy[min(y1, min(y2, y3)) + 1], --dy[max(y1, max(y2, y3))];
	}

	for (int i = 1; i <= 1000000; i++) dx[i] += dx[i - 1], dy[i] += dy[i - 1];
	cin >> M;
	while (M--) {
		cin >> op >> _ >> c;
		if (op == 'x') cout << dx[c] << '\n';
		else cout << dy[c] << '\n';
	}
	return 0;
}
