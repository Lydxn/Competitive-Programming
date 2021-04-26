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
const ll MOD = 1e12 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

const int MX = 200000;
int e[MX]; ll pw[MX + 1];
unordered_map<ll, int> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; char ch; ll ans = 0;
	cin >> N >> M;
	bool trans = false;
	if (N > M) swap(N, M), trans = true;
	vector<vector<bool>> g(N, vector<bool>(M, 0));
	vector<vector<ll>> hsh(M, vector<ll>(N + 1, 0));
	if (trans)
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				cin >> ch, g[j][i] = ch == 'B';
	else
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> ch, g[i][j] = ch == 'B';

	pw[0] = 1;
	for (int i = 1; i <= M; i++) pw[i] = pw[i - 1] * 31 % MOD;
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= N; j++)
			hsh[i][j] = (hsh[i][j - 1] * 31 + g[j - 1][i] + 1) % MOD;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = 0; k < M; k++) e[k] = g[i][k] == g[j][k];
			for (int k = 0; k < M; ) {
				if (!e[k]) { ++k; continue; }
				int r = k;
				while (r < M - 1 && e[r + 1]) ++r;
				mp.clear();
				for (int x = k; x <= r; x++) {
					ll h = (hsh[x][j + 1] - (__uint128_t) hsh[x][i] * pw[j - i + 1] % MOD + MOD) % MOD;
					++mp[h];
				}
				for (auto x : mp) ans += 1LL * x.second * (x.second - 1) / 2;
				k = r + 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
