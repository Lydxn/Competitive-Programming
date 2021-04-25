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

int b[999], a[1000], cnt[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> b[i];
	for (int i = 1; i <= N; i++) {
		a[0] = i;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < N - 1; j++) a[j + 1] = b[j] - a[j];
		for (int j = 0; j < N; j++)
			if (1 <= a[j] && a[j] <= N) ++cnt[a[j]];
		for (int j = 1; j <= N; j++)
			if (cnt[j] != 1) goto nxt;
		cout << a[0];
		for (int j = 1; j < N; j++) cout << ' ' << a[j];
		cout << '\n';
		break; nxt:;
	}
	return 0;
}
