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

int p[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int N, K, A1, A2, B1, B2, cnt = 0;
	cin >> N >> K >> A1 >> A2 >> B1 >> B2;
	for (int i = 1; i <= N; i++) p[i] = i;
	while (true) {
		reverse(p + A1, p + A2 + 1);
		reverse(p + B1, p + B2 + 1);
		++cnt;

		bool good = true;
		for (int i = 1; i <= N; i++) good &= i == p[i];
		if (good) break;
	}

	K %= cnt;
	while (K--) {
		reverse(p + A1, p + A2 + 1);
		reverse(p + B1, p + B2 + 1);
	}

	for (int i = 1; i <= N; i++) cout << p[i] << '\n';
	return 0;
}
