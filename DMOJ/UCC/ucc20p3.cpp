#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int tractors[200];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int H, M, T; string S;
	cin >> H >> T;
	for (int i = 0; i < T; i++) cin >> tractors[i];
	cin >> M >> S;

	int gap = 0, cur = 0;
	for (char c : S) {
		if (c == '1') cur = 0;
		else ++cur;
		gap = max(gap, cur);
	}

	int idx = 0;
	while (tractors[idx + 1] <= gap) ++idx;
	int mt = tractors[idx];
	cout << (H + mt - 1) / mt << '\n';
	return 0;
}
