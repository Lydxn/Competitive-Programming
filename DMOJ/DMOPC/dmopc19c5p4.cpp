#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template <const int MAXN, typename T, const int INDEXING>
struct SparseTable {
	T sparse[32 - __builtin_clz(MAXN)][MAXN]; int lg[MAXN + 1], N;
	T query_op(T a, T b) {return min(a, b);} // range query operation
	template <typename It> void init(It st, It en) {
		N = en - st; std::copy(st, en, sparse[0]);
		lg[1] = 0; for (int i = 2; i <= N; i++) lg[i] = lg[i >> 1] + 1;
		for (int j = 0; j < lg[N]; j++)
			for (int i = 0; i + (1 << j) < N; i++)
				sparse[j + 1][i] = query_op(sparse[j][i], sparse[j][i + (1 << j)]);
	}
	T query(int l, int r) { l -= INDEXING, r -= INDEXING; int k = lg[r - l + 1]; return query_op(sparse[k][l], sparse[k][r - (1 << k) + 1]); }
};

int m[100001], v[100001], temp[100001];
pair<ll, int> sums[100001]; ll sum;
bool vis[100001];
SparseTable<100000, int, 1> st;

void dfs(int cur) {
	sum += m[cur];
	if (v[cur]) dfs(v[cur]);
	if (!vis[cur]) sums[cur] = {sum, cur}, vis[cur] = true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q; ll p, c;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> m[i];
	for (int i = 1; i <= N; i++) cin >> v[i];

	for (int i = 1; i <= N; i++) if (!vis[i]) sum = 0, dfs(i);
	sort(sums + 1, sums + N + 1);
	for (int i = 0; i < N; i++) temp[i] = sums[i + 1].second;
	st.init(temp, temp + N);

	while (Q--) {
		cin >> p >> c;
		if (p >= c) {
			cout << "-1\n";
			continue;
		}
		pair<ll, int> pp = {c - p, INT_MIN};
		ll bound = lower_bound(sums + 1, sums + N + 1, pp) - sums;
		cout << st.query(bound, N) << '\n';
	}
	return 0;
}
