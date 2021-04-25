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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, A, p = -1, m1 = 0, m2 = 0, mx1 = 0, mx2 = 0;
	cin >> N;
	while (N--) {
		cin >> A;
		if (p == -1 || p <= A) mx1 = max(mx1, ++m1);
		else m1 = 1;
		if (p == -1 || p >= A) mx2 = max(mx2, ++m2);
		else m2 = 1;
		p = A;
	}
	cout << max(mx1, mx2) << '\n';
	return 0;
}
