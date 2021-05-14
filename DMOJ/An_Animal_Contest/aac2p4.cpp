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

int a[600], ans[600];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> a[i];
		sort(a, a + N); ll l = 0, r = 0;
		if (N % 2 == 0) {
			for (int i = 0; i < N / 2; i++)
				ans[i * 2] = a[i], ans[i * 2 + 1] = a[N / 2 + i];
			for (int i = 0; i < N / 2; i++)
				l += ans[i * 2], r += ans[i * 2 + 1];
			if (r <= l) { cout << "-1\n"; continue; }
		} else memcpy(ans, a, N * 4);
		for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
	}
	return 0;
}
