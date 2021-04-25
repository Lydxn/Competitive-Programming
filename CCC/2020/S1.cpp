#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll, ll> s[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; double ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i].first >> s[i].second;

	sort(s, s + N);
	for (int i = 0; i < N - 1; i++) {
		ans = max(ans, (double) abs(s[i + 1].second - s[i].second) / (s[i + 1].first - s[i].first));
	}
	cout << fixed << setprecision(5) << ans << '\n';
	return 0;
}
