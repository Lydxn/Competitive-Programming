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

char G[501][501];
int cnt[5];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	for (int i = 0; i < 5 * M + 1; i++)
		for (int j = 0; j < 5 * N + 1; j++)
			cin >> G[i][j];
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int cur = 0;
			for (int a = 5 * i + 1; a < 5 * i + 5; a++)
				for (int b = 5 * j + 1; b < 5 * j + 5; b++)
					cur += G[a][b] == '*';
			++cnt[cur / 4];
		}
	}

	for (int i = 0; i < 5; i++) cout << cnt[i] << ' ';
	cout << '\n';
	return 0;
}
