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

ll s[2000001], psa[2000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> s[i], s[N + i] = s[i];
	for (int i = 1; i <= 2 * N; i++) psa[i] = psa[i - 1] + s[i];
	for (int i = 1, j = 1; i <= N; i++) {
		while (j < N * 2 && psa[j] - psa[i - 1] < psa[N + i - 1] - psa[j]) ++j;
		ll v1 = abs((psa[j] - psa[i - 1]) - (psa[N + i - 1] - psa[j]));
		ll v2 = abs((psa[j - 1] - psa[i - 1]) - (psa[N + i - 1] - psa[j - 1]));
		cout << min(v1, v2) << " \n"[i == N];
	}
	return 0;
}
