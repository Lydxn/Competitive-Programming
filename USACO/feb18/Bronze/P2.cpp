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

int h[100], nxt[100], cnt[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);

	int N;
	cin >> N;
	if (N <= 2) { cout << "1\n"; return 0; }
	for (int i = 0; i < N; i++) cin >> h[i];
	sort(h, h + N);
	
	nxt[0] = 1, nxt[N - 1] = N - 2, cnt[1] = cnt[N - 2] = 1;
	for (int i = 1; i < N - 1; i++) cnt[nxt[i] = h[i] - h[i - 1] <= h[i + 1] - h[i] ? i - 1 : i + 1]++;

	int ans = 0;
	for (int i = 0; i < N; i++) ans += !cnt[i];
	for (int i = 1; i < N; i++) ans += nxt[i] == i - 1 && nxt[i - 1] == i && cnt[i] == 1 && cnt[i - 1] == 1;
	cout << ans << '\n';
	return 0;
}
