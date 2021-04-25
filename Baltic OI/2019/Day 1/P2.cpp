#include <bits/stdc++.h>

using namespace std;

const int MAXN = 501;
bitset<MAXN * MAXN> dp, mask;
string s;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C, M; char c;
	cin >> R >> C >> M;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> c, mask[i * MAXN + j] = c == '.';

	cin >> s; dp = mask;
	for (char x : s) {
		switch (x) {
			case 'N':
				dp >>= MAXN;
				break;
			case 'E':
				dp <<= 1;
				break;
			case 'S':
				dp <<= MAXN;
				break;
			case 'W':
				dp >>= 1;
				break;
			default:
				dp = (dp >> MAXN) | (dp << 1) | (dp << MAXN) | (dp >> 1);
				break;
		}
		dp &= mask;
	}

	cout << dp.count() << '\n';
	return 0;
}
