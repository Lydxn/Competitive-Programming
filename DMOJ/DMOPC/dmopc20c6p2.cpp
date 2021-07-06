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

int a[500000], b[500000], aidx, bidx;
int ansl[500000], ansr[500000], ansidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; bool x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		if (x == 0) a[aidx++] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> x;
		if (x == 0) b[bidx++] = i;
	}
	if (aidx != bidx) { cout << "-1\n"; return 0; }
	for (int i = 0; i < aidx; i++)
		if (a[i] < b[i]) { cout << "-1\n"; return 0; }
	for (int i = 0; i < aidx; i++) {
		if (a[i] == b[i]) continue;
		int r = i;
		while (r + 1 < N && b[r] + 1 == b[r + 1]) ++r;
		ansl[ansidx] = b[i], ansr[ansidx] = a[r], ++ansidx, i = r;
	}
	cout << ansidx << '\n';
	for (int i = 0; i < ansidx; i++) cout << ansl[i] << ' ' << ansr[i] << '\n';
	return 0;
}
