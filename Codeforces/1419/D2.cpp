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

int a[100000], b[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0, j = 1; i < n / 2; j += 2, i++) b[j] = a[i];
	for (int i = n / 2, j = 0; i < n; j += 2, i++) b[j] = a[i];
	int cnt = 0;
	for (int i = 1; i < n - 1; i++) cnt += b[i] < b[i - 1] && b[i] < b[i + 1];
	cout << cnt << '\n';
	for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
	return 0;
}
