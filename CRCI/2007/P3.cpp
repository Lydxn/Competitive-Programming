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

int N, M, X[100], Y[100], Sm[100], Pm[100], Sv[100], Pv[100];

bool f(int S) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		int e = X[i] * S - Y[i], mn = INF;
		for (int j = 0; j <= (e + Sm[i] - 1) / Sm[i]; j++)
			mn = min(mn, Pm[i] * j + Pv[i] * ((e - Sm[i] * j + Sv[i] - 1) / Sv[i]));
		if ((res += mn) > M) return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> X[i] >> Y[i] >> Sm[i] >> Pm[i] >> Sv[i] >> Pv[i];

	int l = 0, r = 100000, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (f(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1 << '\n';
	return 0;
}
