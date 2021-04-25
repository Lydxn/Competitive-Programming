#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, N, K; ll ans = 0;
	cin >> M >> N >> K;

	deque<int> heights(K);
	for (int i = 0; i < K; i++) cin >> heights[i];
	sort(heights.begin(), heights.end());

	while (!heights.empty()) {
		int front = heights.back(); heights.pop_back();
		for (int i = 0; i < M - 1 && !heights.empty(); i++) {
			ans += ++front - heights.front();
			heights.pop_front();
		}
	}

	cout << ans << '\n';
	return 0;
}
