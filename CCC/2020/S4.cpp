#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int psaa[1000001], psab[1000001], psac[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	int len = S.size();
	for (int i = 0; i < len; i++)
		psaa[i + 1] = psaa[i] + (S[i] == 'A'), psab[i + 1] = psab[i] + (S[i] == 'B'), psac[i + 1] = psac[i] + (S[i] == 'C');

	int a = psaa[len], b = psab[len], c = psac[len], ans = INT_MAX;
	for (int i = 0; i < len; i++) {
		if (i + a + b < len) {
			ans = min(ans, a - psaa[i + a] + psaa[i] + b - psab[i + a + b] + psab[i + a] - min(psab[i + a] - psab[i], psaa[i + a + b] - psaa[i + a]));
			ans = min(ans, b - psab[i + b] + psab[i] + a - psaa[i + b + a] + psaa[i + b] - min(psaa[i + b] - psaa[i], psab[i + b + a] - psab[i + b]));
		}
		if (i + a + c < len) {
			ans = min(ans, a - psaa[i + a] + psaa[i] + c - psac[i + a + c] + psac[i + a] - min(psac[i + a] - psac[i], psaa[i + a + c] - psaa[i + a]));
			ans = min(ans, c - psac[i + c] + psac[i] + a - psaa[i + c + a] + psaa[i + c] - min(psaa[i + c] - psaa[i], psac[i + c + a] - psac[i + c]));
		}
		if (i + b + c < len) {
			ans = min(ans, b - psab[i + b] + psab[i] + c - psac[i + b + c] + psac[i + b] - min(psac[i + b] - psac[i], psab[i + b + c] - psab[i + b]));
			ans = min(ans, c - psac[i + c] + psac[i] + b - psab[i + c + b] + psab[i + c] - min(psab[i + c] - psab[i], psac[i + c + b] - psac[i + c]));
		}
	}

	cout << ans << '\n';
	return 0;
}
