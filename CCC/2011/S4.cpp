#include <bits/stdc++.h>

using namespace std;

int a[8], b[8];
pair<int, int> greedy[] =
{
	{0, 0}, // O-
	{1, 1}, {0, 1}, // O+
	{2, 2}, {0, 2}, // A-
	{4, 4}, {0, 4}, // B-
	{3, 3}, {2, 3}, {1, 3}, {0, 3}, // A+
	{5, 5}, {4, 5}, {1, 5}, {0, 5}, // B+
	{6, 6}, {4, 6}, {2, 6}, {0, 6}, // AB-
	{7, 7}, {6, 7}, {5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7} // AB+
};

inline int f(int i, int j) {
	int take = min(a[i], b[j]);
	a[i] -= take, b[j] -= take;
	return take;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) cin >> a[i];
	for (int i = 0; i < 8; i++) cin >> b[i];

	int ans = 0;
	for (const auto& g : greedy) ans += f(g.first, g.second);
	cout << ans << '\n';
	return 0;
}
