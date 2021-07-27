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

int a[300000], l0[300000], r0[300000], l1[300000], r1[300000];
stack<int> sl0, sr0, sl1, sr1;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) {
		while (!sl0.empty() && a[i] > a[sl0.top()]) sl0.pop();
		l0[i] = sl0.empty() ? -1 : sl0.top(), sl0.push(i);
	}
	for (int i = N - 1; i >= 0; i--) {
		while (!sr0.empty() && a[i] >= a[sr0.top()]) sr0.pop();
		r0[i] = sr0.empty() ? N : sr0.top(), sr0.push(i);
	}
	for (int i = 0; i < N; i++) {
		while (!sl1.empty() && a[i] < a[sl1.top()]) sl1.pop();
		l1[i] = sl1.empty() ? -1 : sl1.top(), sl1.push(i);
	}
	for (int i = N - 1; i >= 0; i--) {
		while (!sr1.empty() && a[i] <= a[sr1.top()]) sr1.pop();
		r1[i] = sr1.empty() ? N : sr1.top(), sr1.push(i);
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) ans += 1LL * a[i] * (i - l0[i]) * (r0[i] - i);
	for (int i = 0; i < N; i++) ans -= 1LL * a[i] * (i - l1[i]) * (r1[i] - i);
	cout << ans << '\n';
	return 0;
}
