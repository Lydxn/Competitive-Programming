#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int S[16], ans = 0;
	for (int i = 0; i < 8; i++) cin >> S[i], S[8 + i] = S[i];
	for (int i = 0; i < 8; i++) ans = max(ans, S[i] + S[i + 1] + S[i + 2] + S[i + 3]);
	cout << ans << '\n';
	return 0;
}
