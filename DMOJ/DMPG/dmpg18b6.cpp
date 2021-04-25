#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int w[2000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> w[i];

	sort(w, w + N, greater<int>());
	for (int i = 0, prev = w[0]; i < N; i++) {
		if (prev - w[i] >= K) {
			++cnt;
			prev = w[i];
		}
	}
	cout << cnt + 1 << '\n';
	return 0;
}
