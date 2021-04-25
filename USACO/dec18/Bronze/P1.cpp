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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);

	int c[3], m[3];
	for (int i = 0; i < 3; i++) cin >> c[i] >> m[i];
	for (int i = 0; i < 100; i++) {
		int x = i % 3, y = (i + 1) % 3;
		int pour = min(m[x], c[y] - m[y]);
		m[x] -= pour, m[y] += pour;
	}

	for (int i = 0; i < 3; i++) cout << m[i] << '\n';
	return 0;
}
