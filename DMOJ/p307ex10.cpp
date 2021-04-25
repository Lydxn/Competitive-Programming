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

int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, Y, M, D;
	cin >> T;
	while (T--) {
		cin >> Y >> M >> D;
		bool leap = (Y % 4 == 0 && Y % 100) || (Y % 400 == 0);
		int ans = D;
		for (int i = 0; i < M - 1; i++) ans += m[i];
		cout << ans + (leap && (M > 2)) << '\n';
	}
	return 0;
}
