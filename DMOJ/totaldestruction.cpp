#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int v[1000000], diff[1000000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Q, ans = 0;
	cin >> N >> M >> Q;
	for (int i = 0; i < Q; i++) cin >> v[i];

	sort(v, v + Q);
	for (int i = 0; i < Q - 1; i++) diff[i] = v[i + 1] - v[i];

	sort(diff, diff + Q - 1);
	for (int i = 0; i < Q - M; i++) ans += diff[i] - 1;
	cout << ans + Q << '\n';
	return 0;
}
