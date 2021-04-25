#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q; string N, M;
	cin >> Q;

	while (Q--) {
		cin >> N >> M;
		N = string(M.size() - N.size(), '0') + N;

		int ans = 0, sum = 0;
		for (int i = 0, sz = M.size(); i < sz; i++) {
			if (N[i] != M[i]) ans = max(ans, sum + M[i] - 49 + 9 * (sz - i - 1));
			sum += M[i] - 48;
		}
		cout << max(ans, sum) << '\n';
	}
	return 0;
}
