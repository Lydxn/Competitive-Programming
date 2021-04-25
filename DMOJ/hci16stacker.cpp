#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pair<pii, int> W[1000000];
ll N, BIT[1000001];

void update(int i, ll v) { for (; i <= N; i += i & -i) BIT[i] = max(BIT[i], v); }
ll query(int i) { ll res = 0; for (; i > 0; i -= i & -i) res = max(res, BIT[i]); return res; }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> W[i].first.first, W[i].first.second = i + 1;
	for (int i = 0; i < N; i++) cin >> W[i].second;

	sort(W, W + N, greater<pair<pii, int>>());
	for (int i = 0; i < N; i++) update(W[i].first.second, query(W[i].first.second) + W[i].second);

	cout << query(N) << '\n';
	return 0;
}
