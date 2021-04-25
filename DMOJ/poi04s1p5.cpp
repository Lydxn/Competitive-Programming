// 93/100 TLE :(

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

int mu[50001], spf[50001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 50000; i++) spf[i] = i;
	for (int i = 2; i * i <= 50000; i++)
		if (spf[i] == i)
			for (int j = i * i; j <= 50000; j += i)
				if (spf[j] == j) spf[j] = i;
	mu[1] = 1;
	for (int i = 2; i <= 50000; i++) mu[i] = spf[i] == spf[i / spf[i]] ? 0 : mu[i / spf[i]] * -1;
	for (int i = 2; i <= 50000; i++) mu[i] += mu[i - 1];

	int n, a, b, d;
	cin >> n;
	while (n--) {
		cin >> a >> b >> d; a /= d, b /= d;
		ll ans = 0;
		for (int i = 1, nxt; i <= min(a, b); i = nxt + 1)
			nxt = min(a / (a / i), b / (b / i)), ans += 1LL * (mu[nxt] - mu[i - 1]) * (a / i) * (b / i);
		cout << ans << '\n';
	}
	return 0;
}
