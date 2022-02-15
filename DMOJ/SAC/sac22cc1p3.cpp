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

char g[100][100], t[100][100], u[100][100];
int N, M;

void bruh() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (g[i][j] == 'X') {
				g[i][j] = '.';
				if (i != N - 1)
					g[i + 1][j] = 'X';
			}
		}
	}

	while (true) {
		memcpy(t, g, sizeof(g));
		for (int i = 0; i < N; i++) {
			for (int j = 0, idx = 0; j < M; j++) {
				if (g[i][j] == 'W')
					swap(g[i][idx++], g[i][j]);
				if (g[i][j] == 'X')
					idx = j + 1;
			}
		}

		memcpy(u, g, sizeof(g));
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M; j++) {
				if (g[i][j] == 'W' && g[i + 1][j] == '.')
					u[i][j] = '.', u[i + 1][j] = 'W';
			}
		}
		memcpy(g, u, sizeof(g));

		bool ok = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				ok &= t[i][j] == g[i][j];

		if (ok)
			break;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, op;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> g[i][j];
	cin >> Q;
	while (Q--) {
		cin >> op;
		if (op == 1) bruh();
		else
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) cout << g[i][j];
				cout << '\n';
			}
	}
	return 0;
}
