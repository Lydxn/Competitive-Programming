#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii points[1000];
vector<pii> hull;

bool ccw(pii a, pii b, pii c) { return (b.second - a.second) * (c.first - b.first) - (b.first - a.first) * (c.second - b.second) < 0; }
int dist(int x1, int x2, int y1, int y2) { return ceil(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))); }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) {
		int R, m;
		cin >> R >> m;
		for (int i = 0; i < R; i++) cin >> points[i].first >> points[i].second;

		hull.clear();
		int left = 0;
		for (int i = 1; i < R; i++) if (points[i].first < points[left].first) left = i;

		int p = left, q;
		do {
			hull.push_back(points[p]);
			q = (p + 1) % R;
			for (int i = 0; i < R; i++) if (ccw(points[p], points[i], points[q])) q = i;
			p = q;
		} while (p != left);

		int ans = 0;
		for (int i = 0; i < int(hull.size()); i++) ans += dist(hull[i].first, hull[(i + 1) % hull.size()].first, hull[i].second, hull[(i + 1) % hull.size()].second);
		cout << '$' << ans * m << ".00\n";
	}
	return 0;
}
