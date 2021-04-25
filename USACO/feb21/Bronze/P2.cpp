#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cnt[1011][1011];
bool vis[1011][1011];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, y, ans = 0;
	cin >> N;
	while (N--) {
		cin >> x >> y; x += 2, y += 2; vis[x][y] = true;
		for (pii d : dir) ++cnt[x + d.first][y + d.second];
		for (pii d : dir) {
			if (!vis[x + d.first][y + d.second]) continue;
			int a = cnt[x + d.first][y + d.second];
			ans += a == 3 ? 1 : a == 4 ? -1 : 0;
		}
		ans += cnt[x][y] == 3;
		cout << ans << '\n';
	}
	return 0;
}
