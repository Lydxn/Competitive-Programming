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

struct edge { int X, Y, C; } e[400000];
int col[200000], nxt[200000];
bool vis[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int _, N, X, Y, C; char ch;
	cin >> _ >> N;
	for (int i = 0; i < N; i++) cin >> ch, col[i] = ch - '1', nxt[i] = (i + 1) % N;

	for (int i = 0; i < N - 3; i++) {
		cin >> X >> Y >> C; --X, --Y, --C;
		e[i << 1] = {X, Y, C}, e[i << 1 | 1] = {Y, X, C};
	}

	sort(e, e + ((N - 3) << 1), [&] (edge a, edge b) {
		return (a.Y - a.X + N) % N < (b.Y - b.X + N) % N;
	});

	for (int i = 0; i < N - 3; i++) {
		int X = e[i].X, Y = e[i].Y, C = e[i].C;
		if (nxt[nxt[X]] != Y || vis[X] || vis[Y]) {
			cout << "neispravna triangulacija\n";
			return 0;
		}

		if (!(C + col[X] + col[nxt[X]] == 3 && (C == 0 || col[X] == 0 || col[nxt[X]] == 0))) {
			cout << "neispravno bojenje\n";
			return 0;
		}
		vis[nxt[X]] = true, col[X] = C, nxt[X] = Y;
	}

	cout << "tocno\n";
	return 0;
}
