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

int N;
bool G[11][8][8];

bool in(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("bcs.in", "r", stdin);
	freopen("bcs.out", "w", stdout);

	int K; char c;
	cin >> N >> K;
	for (int i = 0; i < K + 1; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cin >> c, G[i][j][k] = c == '#';

	for (int i = 1; i <= K; i++) {
		for (int j = i + 1; j <= K; j++) {
			for (int ax = -N; ax <= N; ax++) {
				for (int ay = -N; ay <= N; ay++) {
					for (int bx = -N; bx <= N; bx++) {
						for (int by = -N; by <= N; by++) {
							for (int x = 0; x < N; x++) {
								for (int y = 0; y < N; y++) {
									if (G[i][x][y] && !in(x + ax, y + ay)) goto bad;
									if (G[j][x][y] && !in(x + bx, y + by)) goto bad;
									bool ain = in(x - ax, y - ay), bin = in(x - bx, y - by);
									if (!ain && G[i][x - ax][y - ay] && !bin && G[j][x - bx][y - by]) goto bad;
									if (G[0][x][y] != ((ain && G[i][x - ax][y - ay]) | (bin && G[j][x - bx][y - by]))) goto bad;
								}
							}
							cout << i << ' ' << j << '\n'; return 0;
							bad:;
						}
					}
				}
			}
		}
	}
	return 0;
}