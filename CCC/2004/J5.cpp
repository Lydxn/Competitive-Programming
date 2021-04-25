#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int lvl, w, x, incx, incy, x1, x2, y1, y2;
	cin >> lvl >> w >> x;

	vector<pair<int, int>> pts = {{0, 1}, {w, 1}}, temp;
	for (int i = 0; i < lvl; i++) {
		for (int j = 0; j < int(pts.size()) - 1; j++) {
			x1 = pts[j].first, x2 = pts[j + 1].first, y1 = pts[j].second, y2 = pts[j + 1].second, incx = (x2 - x1) / 3, incy = (y2 - y1) / 3;
			temp.emplace_back(x1, y1);
			temp.emplace_back(x1 + incx, y1 + incy);
			temp.emplace_back(x1 + incx - incy, y1 + incx + incy);
			temp.emplace_back(x2 - incx - incy, y2 + incx - incy);
			temp.emplace_back(x2 - incx, y2 - incy);
		}
		temp.emplace_back(pts.back()); pts = temp; temp.clear();
	}

	for (int i = 0; i < int(pts.size()) - 1; i++) {
		temp.emplace_back(pts[i]); x1 = pts[i].first, x2 = pts[i + 1].first, y1 = pts[i].second, y2 = pts[i + 1].second;
		if (x2 - x1) for (int j = min(x1, x2); j <= max(x1, x2); j++) temp.emplace_back(j, y1);
		else         for (int j = min(y1, y2); j <= max(y1, y2); j++) temp.emplace_back(x1, j);
	}
	temp.emplace_back(pts.back()); pts = temp;

	set<int> ys;
	for (const auto& p : pts) {
		if (p.first == x) ys.insert(p.second);
	}

	for (int y : ys) cout << y << ' ';
	cout << '\n';
	return 0;
}
