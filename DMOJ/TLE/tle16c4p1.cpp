#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int w[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, sum = 0, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> w[i];

	sort(w, w + N);
	for (int i = 0; i < N; i++) if (w[i] >= sum) sum += w[i], ++ans;
	cout << ans << '\n';
	return 0;
}
