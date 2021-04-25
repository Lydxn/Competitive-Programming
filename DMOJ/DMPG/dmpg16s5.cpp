#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int pizza[200000];
deque<pair<ll, int>> dq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, p; ll sum = 0, ans = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> p, pizza[i] = pizza[i + N] = p;

	for (int i = 0; i < N << 1; i++) {
		sum += pizza[i];
		while (!dq.empty() && i - dq.front().second > K) dq.pop_front();
		ans = max(ans, sum - dq.front().first);
		while (!dq.empty() && dq.back().first >= sum) dq.pop_back();
		dq.emplace_back(sum, i);
	}

	cout << ans << '\n';
	return 0;
}
