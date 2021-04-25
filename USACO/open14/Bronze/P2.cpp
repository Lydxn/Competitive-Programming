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

pair<int, char> c[100001];
int l[200001], r[200001], p[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("fairphoto.in", "r", stdin);
	freopen("fairphoto.out", "w", stdout);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> c[i].first >> c[i].second;
	sort(c + 1, c + N + 1);
	for (int i = 1; i <= N; i++) p[i] = p[i - 1] + (c[i].second == 'G' ? 1 : -1);
	for (int i = 1; i <= N; i++) r[p[i] + N] = i;
	for (int i = N; i; i--) l[p[i] + N] = i;

	int ans = 0;
	for (int i = 0; i <= 2 * N; i++)
		if (l[i] != r[i]) ans = max(ans, c[r[i]].first - c[l[i] + 1].first);
	for (int i = 1; i <= N; ) {
		int cur = i + 1;
		while (cur <= N && c[cur].second == c[i].second) ++cur;
		ans = max(ans, c[cur - 1].first - c[i].first), i = cur;
	}
	cout << ans << '\n';
	return 0;
}
