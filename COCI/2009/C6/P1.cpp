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

pii k[11];
int ans[10], kidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C; string s;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			if ('1' <= s[j] && s[j] <= '9') {
				k[kidx++] = {j, s[j] - '1'};
				break;
			}
		}
	}

	sort(k, k + kidx, greater<pii>());
	int rnk = 1;
	for (int i = 0; i < kidx; i++) {
		ans[k[i].second] = rnk;
		rnk += k[i].first != k[i + 1].first;
	}

	for (int i = 0; i < kidx; i++) cout << ans[i] << '\n';
	return 0;
}
