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

int holes(int x) {
	return x == 8 ? 2 : x == 0 || x == 6 || x == 9 ? 1 : 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int A, B, mcnt = -1, ans = 0;
	cin >> A >> B;
	for (int i = A; i <= B; i++) {
		int tmp = i, cnt = 0;
		do cnt += holes(tmp % 10), tmp /= 10; while (tmp);
		if (mcnt < cnt) mcnt = cnt, ans = i;
	}
	cout << ans << '\n';
	return 0;
}
