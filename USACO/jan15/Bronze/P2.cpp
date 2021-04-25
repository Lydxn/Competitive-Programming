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

int AD[10001], DB[10001], r[500];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);

	int A, B, N, C, M, ans = INF;
	cin >> A >> B >> N;
	memset(AD, INF, sizeof(AD)); memset(DB, INF, sizeof(DB));
	for (int i = 0; i < N; i++) {
		cin >> C >> M;
		int aidx = INF, bidx = INF;
		for (int j = 0; j < M; j++) {
			cin >> r[j];
			if (r[j] == A) aidx = min(aidx, j);
			if (r[j] == B) bidx = j;
		}

		if (aidx != INF)
			for (int j = aidx; j < M; j++)
				AD[r[j]] = min(AD[r[j]], C);
		if (bidx != INF)
			for (int j = 0; j <= bidx; j++)
				DB[r[j]] = min(DB[r[j]], C);
		if (aidx != INF && bidx != INF && aidx < bidx)
			ans = min(ans, C);
	}

	for (int i = 1; i <= 10000; i++)
		if (AD[i] != INF && DB[i] != INF) ans = min(ans, AD[i] + DB[i]);
	cout << (ans == INF ? -1 : ans) << '\n';
	return 0;
}
