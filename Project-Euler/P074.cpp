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

int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int fsum(int n) {
	int s = 0;
	while (n) s += f[n % 10], n /= 10;
	return s;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	for (int i = 1; i <= 1000000; i++) {
		int t = i, p = -1, cnt = 0;
		do p = t, t = fsum(t), ++cnt;
		while (t != p && t != 169 && t != 363601 && t != 1454 && t != 871 && t != 45361 && t != 872 && t != 45362);
		if ((cnt == 57 && (t == 169 || t == 363601 || t == 1454)) || (cnt == 58 && (t == 871 || t == 45361 || t == 872 || t == 45362)))
			++ans;
	}
	cout << ans << '\n';
	return 0;
}
