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

int deg[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

	int N, a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> a >> b, ++deg[a];

	int idx = -1;
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) {
			if (idx != -1) { cout << "-1\n"; return 0; }
			idx = i;
		}
	}
	cout << idx << '\n';
	return 0;
}
