#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int test[50];
ll dp[1 << 20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; char ch;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < M; j++) {
			cin >> ch;
			if (ch == 'X') test[j] |= 1 << i, flag = false;
		}
		if (flag) for (int j = 0; j < M; j++) test[j] |= 1 << i;
	}

	fill(dp, dp + (1 << N), LLONG_MAX); dp[0] = 0;
	for (int i = 0; i < 1LL << N; i++)
		if (dp[i] != LLONG_MAX)
			for (int j = 0; j < M; j++)
				if (test[j] && __builtin_popcountll(dp[i]) + 1 < __builtin_popcountll(dp[i | test[j]]))
					dp[i | test[j]] = dp[i] | (1LL << j);

	cout << __builtin_popcountll(dp[(1LL << N) - 1]) << '\n';
	vector<int> ans;
	for (int i = 0; i < M; i++) if (dp[(1LL << N) - 1] & (1LL << i)) ans.push_back(i + 1);
	for (int i = 0, sz = ans.size(); i < sz; i++) cout << ans[i] << " \n"[i == sz - 1];
	return 0;
}
