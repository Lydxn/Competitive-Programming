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

	int A, M1, M2;
	while (cin >> A) {
		if (A < 0) break;
		cin >> M1 >> M2;

		int diff = M1 > M2 ? 10000 - M1 + M2 : M2 - M1;
		double ans = 0;
		if (diff <= 10) ans = 659;
		else if (diff <= 30) ans = (diff - 10) * 23.73 + 659;
		else if (diff <= 85) ans = (diff - 30) * 22.71 + 20 * 23.73 + 659;
		else if (diff <= 170) ans = (diff - 85) * 21.78 + 55 * 22.71 + 20 * 23.73 + 659;
		else ans = (diff - 170) * 20.85 + 85 * 21.78 + 55 * 22.71 + 20 * 23.73 + 659;
		cout << fixed << setprecision(2) << "Account #: " << A << "\nBill: " << ans / 100.0 << '\n';
	}
	return 0;
}
