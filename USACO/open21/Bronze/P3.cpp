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

char g[1000][1000];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
set<pair<pii, pii>> ss;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, good = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> g[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (g[i][j] != 'G') continue;
			vector<pii> idxs;
			for (pii d : dir) {
				int nr = i + d.first, nc = j + d.second;
				if (nr >= 0 && nr < N && nc >= 0 && nc < M && g[nr][nc] == 'C')
					idxs.emplace_back(nr, nc);
			}
			if (idxs.size() == 2) ss.insert({min(idxs[0], idxs[1]), max(idxs[0], idxs[1])});
			else if (idxs.size() > 2) ++good;
		}
	}
	cout << good + ss.size() << '\n';
	return 0;
}