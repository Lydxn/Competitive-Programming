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

int diff[5002][5002];
ll psa[5001][5001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, Q, A, B, C, D;
	cin >> N >> M >> K;
	while (K--) {
		cin >> A >> B >> C >> D;
		++diff[A][B], --diff[C + 1][B], --diff[A][D + 1], ++diff[C + 1][D + 1];
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1],
			psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + diff[i][j];

	cin >> Q;
	while (Q--) {
		cin >> A >> B >> C >> D;
		cout << psa[C][D] - psa[A - 1][D] - psa[C][B - 1] + psa[A - 1][B - 1] << '\n';
	}
	return 0;
}
