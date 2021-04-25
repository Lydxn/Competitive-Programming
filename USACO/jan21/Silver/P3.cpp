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

int r[2][1000], c[2][1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a, r[j & 1][i] += a, c[i & 1][j] += a;

	int ansr = 0, ansc = 0;
	for (int i = 0; i < N; i++) ansr += max(r[0][i], r[1][i]);
	for (int i = 0; i < N; i++) ansc += max(c[0][i], c[1][i]);
	cout << max(ansr, ansc) << '\n';
	return 0;
}
