#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int nums[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, d, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> nums[i], ans += nums[i];

	cin >> M;
	while (M--) {
		cin >> a >> d;
		ans -= min(d, min(nums[a], nums[a - 1]));
	}
	cout << ans << '\n';
	return 0;
}
