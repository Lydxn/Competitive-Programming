#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int psa[2][200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; int Q, x, y, z, len, ans;
	cin >> S >> Q; len = S.size();
	for (int i = 0; i < len; i++) psa[0][i + 1] = psa[0][i] + (S[i] == '0'), psa[1][i + 1] = psa[1][i] + (S[i] == '1');

	while (Q--) {
		cin >> x >> y >> z;
		ans = lower_bound(psa[z] + x, psa[z] + len + 1, y + psa[z][x - 1]) - psa[z];
		cout << (ans == len + 1 ? -1 : ans) << '\n';
	}
	return 0;
}
