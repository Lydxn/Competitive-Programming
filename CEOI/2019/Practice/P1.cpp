#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int y[1500], x[1500];
__gnu_pbds::gp_hash_table<int, int> diff;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int h, v;
	cin >> h >> v;
	for (int i = 0; i < h; i++) cin >> y[i];
	for (int i = 0; i < v; i++) cin >> x[i];

	for (int i = 0; i < h; i++)
		for (int j = i + 1; j < h; j++)
			++diff[y[j] - y[i]];

	int cnt = 0;
	for (int i = 0; i < v; i++)
		for (int j = i + 1; j < v; j++)
			cnt += diff[x[j] - x[i]];
	cout << cnt << '\n';
	return 0;
}
