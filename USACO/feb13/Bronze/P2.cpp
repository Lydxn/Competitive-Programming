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

multiset<int> m1, m2;
int a[100000], b[100000], ind[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("crossings.in", "r", stdin);
	freopen("crossings.out", "w", stdout);

	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i], ind[i] = i;
	sort(ind, ind + N, [&] (int &x, int &y) { return a[x] < a[y]; });
	for (int i = 0; i < N; i++) m2.insert(b[i]);
	for (int i = 0; i < N; i++) {
		if (m1.lower_bound(b[ind[i]]) == m1.end() && m2.lower_bound(b[ind[i]]) == m2.begin()) ++ans;
		m1.insert(b[ind[i]]), m2.erase(b[ind[i]]);
	}
	cout << ans << '\n';
	return 0;
}
