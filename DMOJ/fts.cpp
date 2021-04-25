#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, cnt = 0; string S;
	cin >> N >> S;

	bool flag = false;
	for (char c : S) {
		if (c == '1') {
			if (!flag) flag = true, ++cnt;
		} else flag = false;
	}

	cout << 2 * cnt - (S[0] == '1') << '\n';
	return 0;
}
