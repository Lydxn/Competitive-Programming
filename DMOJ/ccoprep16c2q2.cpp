#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dp[31];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num; int cur = 0;
		for (int i = 0; i < 31; i++) if (num & (1 << i)) cur = max(cur, dp[i] + 1);
		for (int i = 0; i < 31; i++) if (num & (1 << i)) dp[i] = cur;
	}

	cout << *max_element(dp, dp + 31) << '\n';
	return 0;
}
