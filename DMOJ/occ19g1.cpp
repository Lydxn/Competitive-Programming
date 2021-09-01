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

int a[100000], v[100000][10];
bool vis[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, k, ans = 0;
	cin >> N >> k;
	for (int i = 0; i < k; i++) cin >> a[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < k; j++)
			cin >> v[i][j];
	while (true) {
		bool bk = true;
		for (int i = 0; i < N; i++) {
			if (vis[i]) continue;
			bool ok = true;
			for (int j = 0; j < k; j++) ok &= a[j] >= v[i][j];
			if (!ok) continue;
			for (int j = 0; j < k; j++) a[j] += v[i][j];
			++ans, vis[i] = true, bk = false;
		}
		if (bk) break;
	}
	cout << ans << '\n';
	return 0;
}
