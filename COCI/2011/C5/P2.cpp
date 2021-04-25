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

int N, M, h[1000000];

int f(int x) {
	ll t = 0;
	for (int i = 0; i < N; i++) t += max(0, h[i] - x);
	return t >= M;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> h[i];

	int l = 0, r = 1e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (f(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << '\n';
	return 0;
}
