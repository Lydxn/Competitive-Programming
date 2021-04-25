#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int, int> mp0;
unordered_map<ll, int> mp1;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll m, b, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> m >> b;
		ans += i - mp0[m]++ + mp1[(m + 1000000000) << 31LL | (b + 1000000000)]++;
	}
	cout << ans << '\n';
	return 0;
}
