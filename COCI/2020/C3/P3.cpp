// WIP (50/110)

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

// probably too slow :)
bitset<90000> B, ans, tmp, msk;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m; char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c, B[i * m + j] = c == '*';
	for (int i = 0; i < m - 1; i++) msk.set(i);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (B[(B ^ ans)._Find_first()]) ans = B;
			B = (B << m) | (B >> (n * m - m));
		}

		tmp.reset();
		for (int j = n * m - m; j >= 0; j -= m) {
			tmp = (tmp << m) | ((B >> (j + 1)) & msk);
			tmp[m - 1] = B[j];
		}
		B = tmp;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ".*"[ans[i * m + j]];
		cout << '\n';
	}
	return 0;
}
