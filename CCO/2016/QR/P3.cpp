#include <bits/stdc++.h>
#define TRI(x) ((x) * ((x) + 1) / 2)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> v;
int mn[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, r, c;
	cin >> N >> M;

	memset(mn, 0x3f, sizeof(mn));
	for (int i = 0; i < M; i++) cin >> r >> c, v.push_back(c), mn[c] = min(mn[c], r);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	ll ans = 0;
	for (int i = 0, ph = 0; i < int(v.size()); i++) {
		int h = N - mn[v[i]] + 1, dist = v[i] - (i ? v[i - 1] : 0);
		cout << h << ' ' << ph << '\n';
		ans += TRI(h) - TRI(max(0, h - ph));
		ph = max(ph - dist, h);
	}
	cout << ans << '\n';
	return 0;
}
