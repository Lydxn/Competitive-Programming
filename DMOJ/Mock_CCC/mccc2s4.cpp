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

int a[100000], s[100000], N;

ll f(int n) {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int sz = N / n;
		for (int j = 0; j < sz; j++) s[j] = a[j * n + i];
		sort(s, s + sz);
		int mid = s[sz >> 1];
		for (int j = 0; j < sz; j++) ans += abs(s[j] - mid);
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll ans = INFL;
	cin >> N;
	if (N == 1) { cout << "0\n"; return 0; }
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 1; i <= N >> 1; i++)
		if (N % i == 0) ans = min(ans, f(i));
	cout << ans << '\n';
	return 0;
}
