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

char G[50][50];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("crosswords.in", "r", stdin);
	freopen("crosswords.out", "w", stdout);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> G[i][j];

	vector<pii> ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			bool h = j < M - 2 && (j == 0 || G[i][j - 1] == '#') && G[i][j] == '.' && G[i][j + 1] == '.' && G[i][j + 2] == '.';
			bool v = i < N - 2 && (i == 0 || G[i - 1][j] == '#') && G[i][j] == '.' && G[i + 1][j] == '.' && G[i + 2][j] == '.';
			if (h || v) ans.emplace_back(i + 1, j + 1);
		}
	}

	cout << ans.size() << '\n';
	for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
	return 0;
}
